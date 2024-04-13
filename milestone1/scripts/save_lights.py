import bpy
import os

# Get the active scene
scene = bpy.context.scene

# Create a list to store the coordinates
light_coordinates = []

# Iterate through all objects in the scene
for obj in scene.objects:
    # Check if the object is a point light
    if obj.type == 'LIGHT' and obj.data.type == 'POINT':
        # Get the location of the light
        location = obj.location
        # Append the coordinates to the list
        light_coordinates.append((location.x, location.y, location.z))

# Get the path of the current .blend file
blend_file_path = bpy.data.filepath

# Set the file name for saving coordinates
file_name = "light_coordinates.txt"

# Combine the blend file path with the file name
file_path = os.path.join(os.path.dirname(blend_file_path), file_name)

# Write the coordinates to a file
with open(file_path, 'w') as file:
    for coordinates in light_coordinates:
        file.write(f"{coordinates[0]} {coordinates[1]} {coordinates[2]}\n")

print(f"Light coordinates saved to: {file_path}")
