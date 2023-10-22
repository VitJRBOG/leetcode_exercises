class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
        elif num < 0:
            num = num + 4294967296

        result = ""

        while num > 0:
            remainder = num % 16

            if remainder > 9:
                if remainder == 10:
                    result = f"a{result}"
                elif remainder == 11:
                    result = f"b{result}"
                elif remainder == 12:
                    result = f"c{result}"
                elif remainder == 13:
                    result = f"d{result}"
                elif remainder == 14:
                    result = f"e{result}"
                elif remainder == 15:
                    result = f"f{result}"
            else:
                result = f"{remainder}{result}"

            num = num // 16

        return result
