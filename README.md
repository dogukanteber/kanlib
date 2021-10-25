# kanlib


## Description

kanlib is a library to provide you basic data structures and additional string handling functions. Supported data structures:

* Dynamic Array(Vector) --> [dynamic_array.h](include/dynamic_array.h)
* Doubly Linked List    --> [linked_list.h](include/linked_list.h)
* Stack                 --> [stack.h](include/stack.h)
* Queue                 --> [queue.h](include/queue.h)
* Hash Table            --> [hash_table.h](include/hash_table.h)
* String                --> [s_string.h](include/s_string.h)

The library will possibly grow in the future. The documentation and code examples have missing parts. I will cover each missing part day by day.

## Platform

The library is written for Linux operating system. Hence, it is not portable to Windows or macOS.

## Build

Copy the repository to your local workspace and run the build script.

```
git clone https://github.com/dogukanteber/kanlib.git
cd kanlib
chmod 755 build.sh && ./build.sh
```

## Documentation

You can find documentation under docs/ directory. Since each function is self-explanatory, you can find a brief description of each function alongside their function definitions. In each doc file, a function definition is given and followed by an explanation about what that function does. Below you can directly access to a specific doc file:

* Dynamic Array     --> [dynamic_array.md](docs/dynamic_array.md)
* Linked List       --> [linked_list.md](docs/linked_list.md)
* Stack             --> [stack.md](docs/stack.md)
* Queue             --> [queue.md](docs/queue.md)
* Hash Table        --> [hash_table.md](docs/hash_table.md) (not implemented)
* String            --> [s_string.md](docs/s_string.md) (not fully implemented)

## Contribution

This library is not an implementation of data structures. Rather, it is a base library for other projects. If you find some functionality that this library lacks, feel free to create an issue or a pull request. Also, if you find a bug feel free to report it.

## License

Released under the revised  GNU GENERAL PUBLIC LICENSE. See [LICENSE](LICENSE) for details.
