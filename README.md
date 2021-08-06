# Terminal morse translator

This is a terminal morse translator written in c++ which is able to translate morse strings, alphebetical strings and text file contents.

## How to use it

The translator has 4 options available:

- ATM (alphabet to morse).
- MTA (morse to aphabet).
- ATMFILE (alphabetical file content translated to morse).
- MTAFILE (morse file content translated to alphabet).

For the files options the file which will be translated need to be in the directory and the result will be writen in a "output.txt" file.

The program can be launched in 2 ways:

#### command line arguments:

You just need to give as arguments one of the previous translation mode and the string or file that you want to translate:

exemple:

```c++

./morseT ATM "Hello World"

>.... . .-.. .-.. ---  .-- --- .-. .-.. -..
```

#### no argument menu:

Choosing this way will launch the program in a infinite loop until you decide to exit.
You will be able to choose the mode and the content that you want to translate.

overview:

```c++

./morseT
Welcome to the morse translator! 
Those are the options available:
-ATM (Alphabet to morse)
-MTA (Morse to alphabet)
-ATMFILE (translate alphabet file to morse)
-MTAFILE (translate morse file to alphabet)

type exit to quit the translator.

Mode:
```