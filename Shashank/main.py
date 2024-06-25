row_wise = True # Change to False for column-wise calculation

row_file = "row_wise.txt"
row_joined = "row_wise_joined.txt"

column_file = "column_wise.txt"
column_joined = "column_wise_joined.txt"

def calculate_accesses(r, c, arr, computation_type):
    if computation_type == 'L':
        arr.extend([
            [r, c],
            [r + 1, c],
            [r - 1, c],
            [r, c + 1],
            [r, c - 1]
        ])
    elif computation_type == 'F':
        arr.extend([
            [r + 2, c],
            [r + 1, c + 1],
            [r + 1, c],
            [r + 1, c - 1],
            [r, c + 1],
            [r, c],
            [r, c - 1],
            [r - 1, c]
        ])
    elif computation_type == 'G':
        arr.extend([
            [r + 1, c + 1],
            [r + 1, c],
            [r, c + 2],
            [r, c + 1],
            [r, c],
            [r, c - 1],
            [r - 1, c + 1],
            [r - 1, c]
        ])


def display_accesses(r, c, arr, computation_type, file):
    arr_size = len(arr) - 1

    file.write(f"{computation_type}({r}, {c}) : [")
    for i in range(arr_size):
        file.write(f"({arr[i][0]}, {arr[i][1]}), ")
    file.write(f"({arr[arr_size][0]}, {arr[arr_size][1]})]")
    file.write("\n")


def main():
    arr = []
    file_name = row_file if row_wise else column_file

    with open(file_name, "w") as f:

        if row_wise:

            for r in range(2, 5):

                for c in range(2, 5):
                    calculate_accesses(r, c, arr, 'L')
                    display_accesses(r, c, arr, 'L', f)
                    arr.clear()
                f.write("\n")
                
                for c in range(2, 5):
                    calculate_accesses(r, c, arr, 'F')
                    display_accesses(r, c, arr, 'F', f)
                    arr.clear()
                f.write("\n")
                
                for c in range(2, 5):
                    calculate_accesses(r, c, arr, 'G')
                    display_accesses(r, c, arr, 'G', f)
                    arr.clear()
                f.write("\n")

        else:

            for c in range(2, 5):

                for r in range(2, 5):
                    calculate_accesses(r, c, arr, 'L')
                    display_accesses(r, c, arr, 'L', f)
                    arr.clear()
                f.write("\n")
                
                for r in range(2, 5):
                    calculate_accesses(r, c, arr, 'F')
                    display_accesses(r, c, arr, 'F', f)
                    arr.clear()
                f.write("\n")
                
                for r in range(2, 5):
                    calculate_accesses(r, c, arr, 'G')
                    display_accesses(r, c, arr, 'G', f)
                    arr.clear()
                f.write("\n")
    print(f"Output written to {file_name}")

if __name__ == "__main__":
    main()
