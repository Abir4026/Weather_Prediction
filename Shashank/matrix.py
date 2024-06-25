row_wise = True # Change to False for column-wise calculation

row_file = "row_wise.txt"
row_joined = "row_wise_joined.txt"

column_file = "column_wise.txt"
column_joined = "column_wise_joined.txt"

file_name = row_file if row_wise else column_file
file_name_joined = row_joined if row_wise else column_joined


# Define a function to parse the tuples from the string
def parse_tuples(tuples_str):
    tuples_list = []
    # Remove surrounding brackets and split by comma
    tuple_pairs = tuples_str.strip('[]').split(', ')
    for pair in tuple_pairs:
        # Remove surrounding parentheses and split by comma
        values = pair.strip('()').split(',')
        # Convert values to integers
        tuple_values = tuple(int(value.strip()) for value in values)
        tuples_list.append(tuple_values)
    return tuples_list

# Initialize lists to store matrices for each column
column1 = []
column2 = []
column3 = []

matrix_name_1 = ""
matrix_name_2 = ""
matrix_name_3 = ""

# Open file for writing
with open(file_name_joined, 'w') as output_file:
    # Read the input file line by line
    with open(file_name, 'r') as file:
        count = 0
        for line in file:
            line = line.strip()
            if line:
                # Split line by colon to separate identifier and tuples
                identifier, tuples_str = line.split(' : ')
                # Extract matrix identifier
                matrix_name = identifier.strip()

                # Parse tuples string to get list of tuples
                tuples_list = eval(tuples_str)  # Safely evaluate the string as a Python expression

                # Distribute tuples into columns based on count
                if count % 3 == 0:
                    column1.extend(tuples_list)
                    matrix_name_1 = matrix_name
                elif count % 3 == 1:
                    column2.extend(tuples_list)
                    matrix_name_2 = matrix_name
                elif count % 3 == 2:
                    column3.extend(tuples_list)
                    matrix_name_3 = matrix_name

                count += 1

                # Print matrices for each group of 3 matrices
                if count % 3 == 0:
                    output_file.write(f"Joined matrices {matrix_name_1}, {matrix_name_2}, {matrix_name_3}:\n")
                    max_length = max(len(column1), len(column2), len(column3))
                    for i in range(max_length):
                        if i < len(column1):
                            output_file.write(str(column1[i]) + ' ')
                        else:
                            output_file.write(' ' * len(str(column1[0])) + ' ')  # to align with the first column
                        if i < len(column2):
                            output_file.write(str(column2[i]) + ' ')
                        else:
                            output_file.write(' ' * len(str(column2[0])) + ' ')  # to align with the second column
                        if i < len(column3):
                            output_file.write(str(column3[i]) + '\n')
                        else:
                            output_file.write('\n')  # to end the line
                    output_file.write('\n')  # Add an empty line after each group of 3 matrices
                    # Clear columns for next group
                    column1.clear()
                    column2.clear()
                    column3.clear()

    # Ensure there's an empty line at the end if the last group was printed
    output_file.write('\n')

print(f"Output written to {file_name_joined}")
