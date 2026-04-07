class Robot:
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height
        self.flag=0
        self.position = 0

    def step(self, num: int) -> None:
        loop_len = (self.width + self.height) * 2 - 4
        self.position = (self.position + num) % loop_len
        flag = 1

    def getPos(self) -> list[int]:
        result = [0, 0]
        if self.position >= 0 and self.position <= self.width - 1:
            result[0] = self.position
            result[1] = 0
        elif self.position >= self.width and self.position < self.width + self.height - 1:
            result[0] = self.width-1
            result[1] = self.position - (self.width - 1)
        elif self.position >= self.width + self.height - 1 and self.position < 2 * self.width + self.height - 2:
            result[0] = (self.width - 1) - (self.position - (self.width + self.height - 2))
            result[1] = self.height - 1
        else:
            result[0] = 0
            result[1] = (self.height - 1) - (self.position - (2 * self.width + self.height - 3))
        return result

    def getDir(self) -> str:
        if self.flag==1 and self.position == 0:
            return "South"
        
        if self.position >= 0 and self.position <= self.width - 1:
            return "East"
        elif self.position >= self.width and self.position < self.width + self.height - 1:
            return "North"
        elif self.position >= self.width + self.height - 1 and self.position < 2 * self.width + self.height - 2:
            return "West"
        else:
            return "South"

# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()