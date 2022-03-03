<!-- ref [https://www.cprogramming.com/tutorial/function-pointers.html] -->
# Function pointer in c and c++

function pointer is a variable that stores the baddress of function that can be called later throuhgh that function pointer

## Initlization and calling

initlization.cpp is a example for initlization and calling of function pointer

## Examples of use

### Function as argument to other function

**Problem**

Example you want to write sort routine. and you want to allow functgion caller to choose the order in which tha data will sorted (ascending or dencending )

**Solution**

you can add flag as argument to the function (ascending or dencending) but this inflexiable solution, we can expse the comparsion function as functiom argument and function caller pass pointer to that comparsion function.

### Callback Functions

Another use for function pointers is setting up "listener" or "callback" functions that are invoked when a particular event happens. The function is called, and this notifies your code that something of interest has taken place.

Why would you ever write code with callback functions? You often see it when writing code using someone's library. One example is when you're writing code for a graphical user interface (GUI). Most of the time, the user will interact with a loop that allows the mouse pointer to move and that redraws the interface. Sometimes, however, the user will click on a button or enter text into a field. These operations are "events" that may require a response that your program needs to handle. How can your code know what's happening? Using Callback functions! The user's click should cause the interface to call a function that you wrote to handle the event.

To get a sense for when you might do this, consider what might happen if you were using a GUI library that had a "create_button" function. It might take the location where a button should appear on the screen, the text of the button, and a function to call when the button is clicked. Assuming for the moment that C (and C++) had a generic "function pointer" type called function, this might look like this:

```C
void create_button( int x, int y, const char *text, function callback_func );
```

Whenever the button is clicked, callback_func will be invoked. Exactly what callback_func does depends on the button; this is why allowing the create_button function to take a function pointer is useful.

## Practical example for function pointer

Let's go back to the sorting example where I suggested using a function pointer to write a generic sorting routine where the exact order could be specified by the programmer calling the sorting function. It turns out that the C function qsort does just that.

From the Linux man pages, we have the following declaration for qsort (from stdlib.h):

```C
void qsort(void *base, size_t nmemb, size_t size,
           int(*compar)(const void *, const void *));
```

Note the use of void\*s to allow qsort to operate on any kind of data (in C++, you'd normally use templates for this task, but C++ also allows the use of void* pointers) because void* pointers can point to anything. Because we don't know the size of the individual elements in a void\* array, we must give qsort the number of elements, the array to be sorted, and length of the input.

But what we're really interested in is the compar argument to qsort:
check (sorting_example.cpp)

it's a function pointer that takes two void \*s and returns an int. This allows anyone to specify how to sort the elements of the array base without having to write a specialized sorting algorithm. Note, also, that compar returns an int; the function pointed to should return -1 if the first argument is less than the second, 0 if they are equal, or 1 if the second is less than the first.
