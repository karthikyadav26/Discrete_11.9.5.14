import matplotlib.pyplot as plt

# Function to read coordinates from a file
def readCoordinatesFromFile(file_path):
    coordinates = []
    with open(file_path, 'r') as file:
        next(file)  # Skip the header
        for line in file:
            term, value = map(int, line.strip().split('\t'))
            coordinates.append((term, value))
    return coordinates

# Read coordinates from data.txt
file_path = 'data.txt'
coordinates = readCoordinatesFromFile(file_path)

# Extract X and Y coordinates for plotting
x_values = [coord[0] for coord in coordinates]
y_values = [coord[1] for coord in coordinates]

# Plot the stem plot with specified colors
plt.stem(x_values, y_values, basefmt="r", markerfmt="ro", linefmt="b-")
plt.xlabel('n')
plt.ylabel('x(n)')
plt.grid(True)
plt.yticks(range(0, max(y_values) + 1, 50))  # Set y-axis step value to 50
plt.show()

