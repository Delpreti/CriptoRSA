def potm(num, expoente, modulo):
    r = 1
    while expoente > 0:
        r = (r * num) % modulo
        expoente -= 1
    return r

class Main():
    @staticmethod
    def program():

        N = 37 * 71
        Dkey = 2291

        encriptado = open("encript.txt", "r", encoding = "utf-8")

        text = encriptado.read()

        result = ""
        for char in text:
            result += chr(potm(ord(char), Dkey, N) - 101)

        print(result)
        encriptado.close()

Main.program()