from typing import List, Dict, Tuple, Optional, Union

# names es una lista de cadenas
def print_names(names: List[str]) -> None:
    for student in names:
        print(student)

# grades es un diccionario con keys=cadenas y values=flotantes
def print_name_and_grade(grades: Dict[str, float]) -> None:
    for student, grade in grades.items():
        print(student, grade)

# Cree su propio tipo de dato:
# Point es un tipo de dato que contiene dos ints (x,y)
Point = Tuple[int, int]

# points es una lista de puntos
def print_points(points: List[Point]):
    for point in points:
        print("X:", point[0], "  Y:", point[1])

def get_api_response() -> Tuple[int, int]:
    successes, errors = ... # Some API call
    return successes, errors

# some_num o es un número entero o es un None
def try_to_print(some_num: Optional[int]):
    if some_num:
        print(some_num)
    else:
        print('Value was None!')
        
# grade o es un entero o es una cadena        
def print_grade(grade: Union[int, str]):
    if isinstance(grade, str):
        print(grade + ' percent')
    else:
        print(str(grade) + '%')                
