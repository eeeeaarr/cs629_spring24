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

    first = True
    previous_point = 0
    for bezier_point in spline.bezier_points:
        if first:
            previous_point = bezier_point
            first = False
        else:
            p0 = previous_point.co
            c0 = previous_point.handle_right
            c1 = bezier_point.handle_left
            p1 = bezier_point.co
            bezier_coordinates.append(f"p={p0.x} {p0.y} {p0.z}")
            bezier_coordinates.append(f"c={c0.x} {c0.y} {c0.z}")
            bezier_coordinates.append(f"c={c1.x} {c1.y} {c1.z}")
            bezier_coordinates.append(f"p={p1.x} {p1.y} {p1.z}")
            previous_point = bezier_point

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
