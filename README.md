# Lambda-NFA accepter
O implementare rudimentară în C++ a unui [automat finit nedeterminist](https://ro.wikipedia.org/wiki/Automat_finit_nedeterminist) cu translații Λ.

Inputul dat in fișierul text [input.txt](https://github.com/Ursawarlord/lambda-NFA-accepter/blob/master/input.txt) este corespondent următorului automat:
Codul în C++ se găsește în [main.cpp](https://github.com/Ursawarlord/lambda-NFA-accepter/blob/master/main.cpp).

<img src="https://github.com/Ursawarlord/lambda-NFA-accepter/blob/master/media/input.png">


Acesta răspunde următoarelor exemple:
```
abxyyyxyby - TRUE
bcax - TRUE
bcbxxy - FALSE
abyyxz - FALSE
abyyxyx - TRUE
```
