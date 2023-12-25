import random
import winsound
import time

# the beep function
# -------------------------------------------------------------------------
def beep(frequency, duration):
    winsound.Beep(frequency, duration)

# accessing and storing file data
with open('list_export.txt', 'r') as file:
    word_list = [line.strip() for line in file]
empty_list = []
random_word = random.choice(word_list)
gameover = False
chances = 7

# ----------------------------------------------------------------------------
print("Hello welcome to hangman")

for _ in random_word:
    empty_list.append("_")
print(" ".join(empty_list))

def function(user_input):
    global chances
    global gameover
    for index in range(len(random_word)):
        letter = random_word[index]
        if letter == user_input:
            empty_list[index] = letter
    if user_input not in random_word:
        chances -= 1
        beep(1000, 500)
        print(f"You have {chances} chances left")
    if user_input in random_word:
        beep(720, 300)
    if chances <= 0:
        print("YOU LOST")
        print(random_word)
        gameover = True
    print(" ".join(empty_list))
    if "_" not in empty_list:
        gameover = True
        print("YOU WON")

while not gameover:
    user_input = input("Guess a letter: ")
    function(user_input)
