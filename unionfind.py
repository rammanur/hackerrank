# Dynamic connectivity Notes:

# Efficient data structure for Union Find:
# - number of objects N can be huge
# - number of operations M can be huge
# - Find queries and union commands can be intermixed

public class UF
UF(int N) # initialize union find datastructure with N objects (0 to N-1)
void union(int p, int q) # add connection between p and q
boolean connected(int p, int q) # are p and q in the same component?
int find(int p) #component identifier for p(0 to N-1)
int count() #number of components


Dynamic connectivity Client:
- Read in number of objects N from stdin
- Repeatedly: read in pairs of integers from stdin and if they are not
  yet connected, connect them and print out pair

public static void main(String[] args)
{
  int N = StdIn.readInt();
  UF uf = new UF(N);

  while (!StdIn.isEmpty()) {
    int p = StdIn.readInt();
    int q = StdIn.readInt();

    if (!uf.connected(p, q)) {
      uf.union(p, q);
      StdOut.println(p + "" + q);
    }
  }
}

more tinyUF.txt
10 
4 3
3 8
6 5
9 10
8 9
5 0
7 2
6 1
1 0
6 7
