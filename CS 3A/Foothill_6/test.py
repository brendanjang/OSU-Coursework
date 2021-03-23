sp_words = []
fo = open("1kwords.sp.txt", encoding="utf8")
for line in fo:
    sp_words.append(line.strip())
fo.close()

print(sp_words)
