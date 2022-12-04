# create list
total_score = ["BX", "CY", "AZ", "AX", "BY", "CZ", "CX", "AY", "BZ"]

def answer(input_list):
    with open("aoc_2022_d2.txt") as input:
        return sum(map(lambda pair: input_list.index(pair) + 1, map(lambda line: ''.join(line.strip().split()), input.readlines())))

# get answer      
print(answer(total_score))
