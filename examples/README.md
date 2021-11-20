### Tip When Working With Integers

Each data structure is implemented to work with generic types. Therefore, void pointers are used. As you know, in order to call a function that uses void pointers, you have to cast it the type. When using return values, you also need to cast the returned value the type you want to work on.

Suppose we are using stack. Well, we need to push some value to it. So we call the push function whose signature is ```void stack_push(stack* s, void* val)```. If we want to push 1 to stack my_stack, we would write this:

 ```stack_push(my_stack, (int*) val);```

 So far so good. When we want to get the element at the top, we would call the top function whose signature is ```void* stack_top(stack* s)```. If we want to get the top element, we need to cast the returned value:

 ```int my_value = (int*) stack_top(my_stack);```

 This should work most of the time but the compiler throws warning. That is because size of int is 4 while size of void* is 8 bytes. When we are casting an int value to void* it is all good. But, when we cast void* to int we might lose some value because we are trying to assing 8 bytes value to 4 bytes. That is why the complier complains. We can avoid this problem by using ```intptr_t```.

 intptr_t is defined in ```stdint.h```.

 So, we can modify

  ```int my_value = (int*) stack_top(my_stack);```

  to this:

   ```int my_value = (intptr_t) stack_top(my_stack);```

   And that will remove the warning. Check out above programs if you would like gain an insight about how to use the library.