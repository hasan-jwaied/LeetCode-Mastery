import os
import re

README_PATH = "README.md"
START_MARKER = "\n"
END_MARKER = "\n"

LANGUAGES = {
    "C": { "ext": ".c", "icon": "✅ C" },
    "C++": { "ext": ".cpp", "icon": "✅ C++" },
    "Python": { "ext": ".py", "icon": "✅ Python" },
    "Java": { "ext": ".java", "icon": "✅ Java" }
}

def generate_table():
    problems = []
    
    for root, dirs, files in os.walk("."):
        if "/." in root or root == ".":
            continue
            
        path_parts = root.split(os.sep)
        if len(path_parts) >= 3:
            topic_folder = path_parts[1]
            problem_folder = path_parts[2]            
            match = re.match(r"(\d+)-(.+)", problem_folder)
            if match:
                prob_num = int(match.group(1))
                prob_name_raw = match.group(2)
                prob_name_clean = prob_name_raw.replace("-", " ")                
                leetcode_url = f"https://leetcode.com/problems/{prob_name_raw.lower()}/"
                
                lang_status = {}
                for lang, info in LANGUAGES.items():
                    has_file = any(f.endswith(info["ext"]) for f in files)
                    if has_file:
                        filename = next(f for f in files if f.endswith(info["ext"]))
                        rel_path = f"./{topic_folder}/{problem_folder}/{filename}".replace("\\", "/")
                        rel_path = rel_path.replace(" ", "%20")
                        lang_status[lang] = f"[{info['icon']}]({rel_path})"
                    else:
                        lang_status[lang] = "⏳"
                
                problems.append({
                    "num": prob_num,
                    "name": prob_name_clean,
                    "url": leetcode_url,
                    "topic": topic_folder.replace("-", " "),
                    "status": lang_status
                })

    problems.sort(key=lambda x: x["num"])

    table = "| # | Problem | Topic | C | C++ | Python | Java |\n"
    table += "| :--- | :--- | :--- | :---: | :---: | :---: | :---: |\n"
    
    for p in problems:
        num_str = f"{p['num']:04d}"
        row = f"| {num_str} | [{p['name']}]({p['url']}) | {p['topic']} | "
        row += f"{p['status']['C']} | {p['status']['C++']} | "
        row += f"{p['status']['Python']} | {p['status']['Java']} |\n"
        table += row

    return table

def update_readme(new_table):
    with open(README_PATH, "r", encoding="utf-8") as file:
        content = file.read()

    pattern = re.compile(f"({START_MARKER}).*?({END_MARKER})", re.DOTALL)
    new_content = pattern.sub(rf"\1\n{new_table}\n\2", content)

    with open(README_PATH, "w", encoding="utf-8") as file:
        file.write(new_content)
    print("✅ README.md has been successfully updated! ✅")

if __name__ == "__main__":
    table_markdown = generate_table()
    update_readme(table_markdown)