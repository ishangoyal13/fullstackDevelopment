import argparse



# takes the count of the words in text and secret message and divides how many words would be there in each line
def perLine(n1, n2):  # n1 -> count of words in text, n2 -> count of words in secret
    global n
    if (n1 > n2):
        n = 1
    else:
        n = n2//n1


# convert each letter of secret to binary
def binConvert(array):
    for word in range(len(array)):
        char = "".join(format(ord(letter), 'b')
                       for letter in array[word])
        char = char.replace('1', "\t")
        char = char.replace('0', " ")
        array[word] = char


# convert binary back to characters
def textConvert(array):
    for sentence in range(len(array)):
        array[sentence] = array[sentence].replace('\t', '1')
        array[sentence] = array[sentence].replace(' ', '0')


def hideText(arrTex, arrSec,args):
    perLine(len(arrTex), len(arrSec))
    binConvert(arrSec)
    i = 0
    for line in range(len(arrTex)):
        if (line != (len(arrTex) - 1)):
            var = ""
            sentence = "\n"
            if (i < len(arrSec)):
                for x in range(n):  # add words divided according to perLine function to each line
                    var += arrSec[i] + chr(160)
                    i += 1
                sentence = f"{chr(160)}{var}\n"
            arrTex[line] += sentence
        else:  # The last line need not include a new line tab (\n) at its last
            var = ""
            sentence = ""
            if (i < len(arrSec)):
                # add all the remaining words of secret to the last line if exists
                while (i != len(arrSec)):
                    var += arrSec[i] + chr(160)
                    i += 1
                sentence = f"{chr(160)}{var}"
            arrTex[line] += sentence

    file = open(args.output, "w+")
    for line in arrTex:
        file.write(line)

    file.close()


def unHideText(arrTex):
    textConvert(arrTex)
    sentence = ""
    for line in arrTex:
        lines = list(line.split(chr(160)))
        if (len(lines) > 1 and len(lines) != 2):
            for z in range(1, len(lines)-1):
                words = lines[z]
                word = ""
                letter = ""
                for i in range(len(words)+1):
                    if (i % 7 == 0 and i != 0):
                        word += chr(int(letter, 2))
                        letter = ""
                        if (i < len(words)):
                            letter += words[i]

                    else:
                        letter += words[i]

                sentence += word + " "
    print(f"\n\n\u001b[31;3mSecret text: {sentence}\u001b[0m\n\n")


def main():
    print('''\u001b[32m
                    _________.__                           .___
      ____   ____  /   _____/|  |_________  ____  __ __  __| _/
    _/ __ \ /    \ \_____  \ |  |  \_  __ \/  _ \|  |  \/ __ |
    \  ___/|   |  \/        \|   Y  \  | \(  <_> )  |  / /_/ |
     \___  >___|  /_______  /|___|  /__|   \____/|____/\____ |
         \/     \/        \/      \/                        \/
                                            -- Developed By Akarsh\u001b[0m''')
    parser = argparse.ArgumentParser()
    parser.add_argument("-e", "--encode", help="encode", action="store_true")
    parser.add_argument("-d", "--decode", help="decode", action="store_true")
    parser.add_argument("-p", "--path", help="path to text file")
    parser.add_argument("-o", "--output", help="path to output")
    parser.add_argument("-s", "--secret", help="secret text")
    parser.add_argument("-v","--version",help="version",action="store_true")
    args = parser.parse_args()

    if (args.encode and args.path and args.output and args.secret):
        try:
            file = open(args.path, 'r')
            arrText = list(file.readlines())
            arrSecret = list(args.secret.split())
            for line in range(len(arrText)):
                if '\n' in arrText[line]:
                    arrText[line] = arrText[line].replace('\n', "")
            hideText(arrText, arrSecret,args)
            file.close()
            print(
                f"\n\n\u001b[31;3mFile saved to output path: {args.output}\n\n")
        except:
            print("Bad file path!")

    elif (args.decode and args.path):
        try:
            file = open(args.path, 'r')
            lines = list(file.readlines())
            file.close()
            unHideText(lines)

        except:
            print("Invalid file path!")

    elif (args.version):
        print("\n\nversion: 1.0.4")

    else:
        print("\u001b[31;1m\nTo encode:")
        print(
            "\tpython3 enShroud.py -e -p PATH_TO_TEXT_FILE  -o PATH_TO_OUTPUT -s SECRET_MESSAGE")
        print("To decode:")
        print("\tpython3 enShroud.py -d -p PATH_TO_TEXT_FILE\n\n\u001b[0m")


if __name__ == "__main__":
    main()
