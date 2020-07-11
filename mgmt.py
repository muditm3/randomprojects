#python program to make and manage a teachers' student database management system

import csv
from sys import argv
from cs50 import get_int, get_string

def main(argv):

    if len(argv) != 2:
        print("Usage: python mgmt.py filename.csv")
        exit(1)

    file = open(argv[1], "r+")

    print("Enter the action you want to perform from the following menu: ")
    print("1. Write a new entry")
    print("2. Read the entries")
    action = get_int("Enter: ")

    if action == 1:
        enrNo = get_int("Enter enrNo: ")
        name = get_string("Enter name: ")
        branch = get_string("Enter branch: ")
        batch = get_string("Enter batch: ")
        marks = get_int("Enter marks: ")

        writer = csv.writer(file)
        writer.writerow((enrNo, name, branch, batch, marks))
    elif action == 2:
        print("Displaying the entries: ")
        reader = csv.reader(file, delimiter = ' ', quotechar = '|')
        for row in reader:
            print(row)

if __name__ == "__main__":
    main(argv)