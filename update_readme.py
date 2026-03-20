import os
import re

README_PATH = "README.md"

LANGUAGES = {
    "C": { "ext": ".c", "icon": "✅ C" },
    "C++": { "ext": ".cpp", "icon": "✅ C++" },
    "Python": { "ext": ".py", "icon": "✅ Python" },
    "Java": { "ext": ".java", "icon": "✅ Java" }
}

DIFFICULTY_MAP = {
    "E": "🟢",
    "M": "🟡",
    "H": "🔴"
}

README_HEADER = """# My LeetCode Solutions

## Progress Dashboard

"""

README_FOOTER = """
> **Difficulty:** 🟢 Easy | 🟡 Medium | 🔴 Hard\n
> **Status:** `✅` Completed | `⏳` Work in progress
"""

def generate_table():
    problems = []
    
    for root, dirs, files in os.walk("."):
        if "/." in root or root == ".":
            continue
            
        path_parts = root.split(os.sep)
        if len(path_parts) >= 3:
            topic_folder = path_parts[1]
            problem_folder = path_parts[2]            
            
            match = re.match(r"(\d+)-([EMH])-(.+)", problem_folder)
            
            if match:
                prob_num = int(match.group(1))
                diff_letter = match.group(2)
                prob_name_raw = match.group(3)
                
                prob_name_clean = prob_name_raw.replace("-", " ")                
                leetcode_url = f"https://leetcode.com/problems/{prob_name_raw.lower()}/"
                
                difficulty_icon = DIFFICULTY_MAP.get(diff_letter, "⚪")
                
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
                    "difficulty": difficulty_icon,
                    "topic": topic_folder.replace("-", " "),
                    "status": lang_status
                })
            else:
                print(f"⚠️ SKIPPED: Folder '{problem_folder}' has an invalid name format.")
                print("   USAGE: <ProblemNumber>-<Difficulty>-<Problem-Name>")
                print("   Example: 0053-M-Maximum-Subarray (Strictly use E, M, or H)\n")

    problems.sort(key=lambda x: x["num"])

    table = "| # | Problem | Topic | C | C++ | Python | Java |\n"
    table += "| :--- | :--- | :--- | :---: | :---: | :---: | :---: |\n"
    
    for p in problems:
        num_str = f"{p['num']:04d}"
        row = f"| {num_str} | {p['difficulty']} [{p['name']}]({p['url']}) | {p['topic']} | "
        row += f"{p['status']['C']} | {p['status']['C++']} | "
        row += f"{p['status']['Python']} | {p['status']['Java']} |\n"
        table += row

    return table

def overwrite_readme():
    print("Scanning folders and generating table...\n")
    table_markdown = generate_table()
    full_content = README_HEADER + table_markdown + README_FOOTER

    with open(README_PATH, "w", encoding="utf-8") as file:
        file.write(full_content)
        
    print("✅ README.md has been cleanly generated from scratch! ✅")

if __name__ == "__main__":
    overwrite_readme()