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
        Ekey = 11

        f = open("teste.txt")
        texto = f.read()
        f.close()

        texto += " funciona!"
        # print(texto)

        encriptado = open("encript.txt", "w", encoding = "utf-8")

        result = ""
        for char in texto:
            result += chr(potm(ord(char) + 101, Ekey, N))

        encriptado.write(result)
        encriptado.close()

Main.program()