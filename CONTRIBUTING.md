* Header files require `#pragma once` to avoid issues cyclic declarations.
* All public funtions must work in python and C++. Also they need to have
  a python unit test and fully documented.
* All API classes must have a isolated example usage. If the class is too
  complex and require multiple other classes to work, it will be necessary to
  create a sample project and then direct link to the file where the class is
  used
* use `auto` where possible. It's ok, you will live.
