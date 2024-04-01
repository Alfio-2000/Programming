#Calculate cos,sen, tan of an angle in radians and in degrees
import math
print("I can calculate trigonometric functions of an angle in radians and in degrees.\n")

angle=float(input("Insert radians angle:"))
radians=math.radians(angle)
cos=math.cos(radians)
sin=math.sin(radians)
tan=math.tan(radians)
print(f"You obtained (in radians): cos({radians:.2f})={cos:.2f}, sin({radians:.2f})={sin:.2f}, tan({radians:.2f})={tan:.2f}\n")

#Now, i calculate them in degrees
degrees=math.degrees(angle)
cos=math.cos(degrees)
sin=math.sin(degrees)
tan=math.tan(degrees)
print(f"You obtained (in degrees): cos({degrees:.2f})={cos:.2f}, sin({degrees:.2f})={sin:.2f}, tan({degrees:.2f})={tan:.2f}\n")  #1

#1: Functions math.degrees, math.radians is necessary to calculate radians and degrees angles.
