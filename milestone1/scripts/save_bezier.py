import bpy
import os

# Get the active scene
scene = bpy.context.scene

# Find the first Bezier curve in the scene
bezier_curve = next((obj for obj in scene.objects if obj.type == 'CURVE' and obj.data.splines[0].type == 'BEZIER'), None)

if bezier_curve:
    # Extract control points and endpoints from the Bezier curve
    spline = bezier_curve.data.splines[0]

    # Create a list to store the coordinates
    bezier_coordinates = []

    for bezier_point in spline.bezier_points:
        p = bezier_point.co
        c_left = bezier_point.handle_left
        c_right = bezier_point.handle_right
        bezier_coordinates.append(f"c={c_left.x} {c_left.y} {c_left.z}")
        bezier_coordinates.append(f"p={p.x} {p.y} {p.z}")
        bezier_coordinates.append(f"c={c_right.x} {c_right.y} {c_right.z}")

    # Get the path of the current .blend file
    blend_file_path = bpy.data.filepath

    file_name = "bezier.txt"

    # Combine the blend file path with the file name
    file_path = os.path.join(os.path.dirname(blend_file_path), file_name)

    # Write the coordinates to a file
    with open(file_path, 'w') as file:
        for coordinates in bezier_coordinates:
            file.write(f"{coordinates}\n")

    print(f"Bezier curve coordinates saved to: {file_path}")
else:
    print("No Bezier curve found in the scene.")
