[#CATALAN NUMBERS](https://www.geeksforgeeks.org/applications-of-catalan-numbers/)

Similar to Fibbonaci Numbers

Base cases C[0]=C[1]=1

C[n] = C[0]*C[n-1] + C[1]*C[n-2] + ........ + C[n-2]*C[1] + C[n-1]*C[0]

Formula C[n] = (2n)!/((n+1)!n!) = (2nCn)/(n+1)

Applications:-

* Number of possible BST with n distinct numbers
* * Number of ways to draw n non-intersecting chords with 2n points on circle 
  * Number of ways a convex polygon of n+2 sides can split into triangles by connecting vertices.
* Number of valid expression for n pairs of paranthesis.
* Number of possible binary trees with n+1 leaves.
* Number of Dyck words of length 2n. A Dyck word is a string consisting of n X’s and n Y’s such that no initial segment of the string has more Y’s than X’s.  For example, the following are the Dyck words of length 6: XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.
* Number of ways to tile a stairstep shape of height n with n rectangles.

