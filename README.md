# C++ Modules 05–09

42 C++ exercises covering exceptions, casts, templates, containers, and algorithms. Each exercise has its own sources and, where provided, its own Makefile.

## Contents

| Directory | Focus |
| --- | --- |
| [CPP-05](CPP-05) | Bureaucrats, forms, exceptions, abstract forms, and an intern factory |
| [CPP-06](CPP-06) | Scalar conversion, serialization, and runtime type identification |
| [CPP-07](CPP-07) | Function templates, array iteration, and a templated array |
| [CPP-08](CPP-08) | Container search, spans, and an iterable stack adapter |
| [CPP-09](CPP-09) | Earlier Module 09 work |
| [NEW_CPP_09](NEW_CPP_09) | Bitcoin exchange, reverse Polish notation, and merge-insert sorting exercises |

## Build and usage

Requires Make and a C++ compiler available as `c++`. The supplied nonempty Makefiles use C++98 with `-Wall -Wextra -Werror`. There is no root Makefile.

Examples from the repository root:

```sh
make -C CPP-05/ex00
./CPP-05/ex00/Bureaucrat

make -C CPP-06/ex00
./CPP-06/ex00/convert 42

make -C NEW_CPP_09/ex01
./NEW_CPP_09/ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Build other exercises from their own directories. Refer to each Makefile's `NAME` and demonstration `main.cpp` for its executable and arguments. Nonempty Makefiles provide `clean`, `fclean`, and `re` targets.

## Snapshot limitations

Some folders contain unfinished work. A rebuild with GCC 13 identified these issues:

| Exercise | Build or checkout issue |
| --- | --- |
| `CPP-06/ex02` | Empty Makefile |
| `CPP-07/ex02` | Unresolved `Boundlimit` exception type in `main.cpp` |
| `CPP-08/ex00` | `std::find` is unavailable with the current includes |
| `CPP-08/ex01` | Warnings promoted to errors, including initialization order and a missing return |
| `CPP-09` | Earlier work with incomplete build setup |
| `NEW_CPP_09/ex00` | `ifstream::open` receives a `std::string` under C++98; required `data.csv` is also absent |
| `NEW_CPP_09/ex02` | `std::numeric_limits` is unavailable with the current includes |

The examples above compiled in that environment; this is not a claim that every exercise is complete or passes its subject requirements.

## Concepts practiced

Exception safety, class hierarchies, casts, serialization, templates, iterators, STL containers, parsing, and algorithm design.
