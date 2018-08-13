# Example of an instance variable
class ClassA():
    def __init__(self):
        self.y = 3

# Example of a static variable
class ClassB():
    x = 7

# Create class instances
a = ClassA()
b = ClassB()

# Two ways to print the STATIC variable.
print(b.x)
print(ClassB.x) # This is the proper way to do it.

# One way to print an INSTANCE variable.
# The second generates an error, because we don't know what instance
# to reference.
print(a.y)      # This is the proper way to do it
print(ClassA.y) # This way generates an error

