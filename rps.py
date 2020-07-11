#Python program to play rock, paper and scissors

from cs50 import get_string
import random

def game():
    playerWins, compWins = 0, 0

    while playerWins < 5  and compWins < 5:
        yourTurn = get_string("\nYour Turn: ")

        compTurn = random.choice(["rock", "paper", "scissor"])

        print(f"\nComp's Turn: {compTurn}")

        if (yourTurn == "rock"  and  compTurn == "paper")  or  (yourTurn == "paper"  and compTurn == "scissor")  or  (yourTurn == "scissor"  and  compTurn == "rock"):
            compWins += 1
        elif (yourTurn == "rock"  and  compTurn == "scissor")  or  (yourTurn == "paper"  and compTurn == "rock")  or  (yourTurn == "scissor"  and  compTurn == "paper"):
            playerWins += 1

        print(f"\n\nYour Wins: {playerWins}\t\tComp's Wins: {compWins}")

    if playerWins == 5:
        print("\nYou Win!")
    else:
        print("\nComputer Wins!")

def main():
    print("Let's play Rock, Paper and Scissors")
    print("\nYou have to win 5 times first to win. And you have to type in what you choose")

    print("\n\n\t\tDEMO")
    print("\nYour turn: rock\t\tComputer's Turn: paper")
    print("\nComputer wins!\n")

    play = "y"

    while play == "y":
        game()
        play = get_string("\nDo you wanna play again?(y/n)")
        print("Okay")

if __name__ == "__main__":
    main()