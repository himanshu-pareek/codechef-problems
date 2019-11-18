import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
 
public class Main {
 
	static StreamTokenizer in;
	static PrintWriter out;
	
	static int nextInt() throws IOException {
		in.nextToken();
		return (int)in.nval;
	}
	
	static String nextString() throws IOException {
		in.nextToken();
		return in.sval;
	}
 
	public static void main(String[] args) throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//in = new StreamTokenizer(new BufferedReader(new FileReader("bogosort.in")));
		out = new PrintWriter(System.out);
		//out = new PrintWriter("bogosort.out");
		
		//long tm = System.currentTimeMillis();
 
		for (int t = nextInt(); t > 0; t--) {
			int n = nextInt();
			out.println(solve(n));
		}
		
		out.flush();
		
		//System.out.println(System.currentTimeMillis() - tm);
	}
 
	static final int MAX = 150;
	static BigInteger[] f = new BigInteger[MAX+1];
	static {
		f[0] = BigInteger.ONE;
		for (int i = 1; i <= MAX; i++) f[i] = f[i-1].multiply(new BigInteger(i+""));
	}
	static BigInteger[] q = new BigInteger[MAX+1];
	static {
		q[0] = BigInteger.ONE;
		q[1] = BigInteger.ZERO;
		for (int i = 2; i <= MAX; i++) q[i] = f[i-1].multiply(new BigInteger((i-2)+"")).add(f[i-2]);
	}
	
	static Rational[] memo = new Rational[MAX+1];
	static Rational solve(int n) {
		if (memo[n] != null) return memo[n];
		if (n == 1) return memo[n] = new Rational("0");
		
		Rational res = new Rational(f[n], BigInteger.ONE).add(solve1(n));
		
		res = res.multiply(new Rational(BigInteger.ONE, f[n].subtract(q[n])));
		
		return memo[n] = res;
	}
	
	static Rational[] memo1 = new Rational[MAX+1];
	static Rational solve1(int n) {
		if (memo1[n] != null) return memo1[n];
		if (n == 1) return memo1[n] = new Rational("0");
		
		return memo1[n] = solve1(n-1).add(solve2(n-1)).add(solve(n-1).multiply(new Rational(q[n-1], BigInteger.ONE)));
	}
	
	static Rational[] memo2 = new Rational[MAX+1];
	static Rational solve2(int n) {
		if (memo2[n] != null) return memo2[n];
		if (n == 1) return memo2[n] = new Rational("0");
		
		return memo2[n] = solve2(n-1).add(solve(n).multiply(new Rational(q[n], BigInteger.ONE)));
	}
}
 
class Rational {
	BigInteger nom, denom;
	
	Rational(BigInteger nom, BigInteger denom) {
		this.nom = nom;
		this.denom = denom;
		reduce();
	}
	
	Rational(String s) {
		String[] t = s.split("/");
		this.nom = new BigInteger(t[0]);
		this.denom = t.length > 1 ? new BigInteger(t[1]) : BigInteger.ONE;
		reduce();
	}
	
	private void reduce() {
		if (nom.equals(BigInteger.ZERO) && denom.equals(BigInteger.ZERO)) {
			nom = BigInteger.ZERO;
			denom = BigInteger.ONE;
		}
		else {
			BigInteger g = nom.gcd(denom);
			nom = nom.divide(g);
			denom = denom.divide(g);
		}
		
		if (denom.compareTo(BigInteger.ZERO) < 0) {
			nom = nom.negate();
			denom = denom.negate();
		}
	}
	
	public String toString() {
		return nom + (!denom.equals(BigInteger.ONE) ? "/" + denom : "");
	}
	
	Rational add(Rational b) {
		return new Rational(nom.multiply(b.denom).add(denom.multiply(b.nom)), denom.multiply(b.denom));
	}
	
	Rational subtract(Rational b) {
		return new Rational(nom.multiply(b.denom).subtract(denom.multiply(b.nom)), denom.multiply(b.denom));
	}
	
	Rational multiply(Rational b) {
		return new Rational(nom.multiply(b.nom), denom.multiply(b.denom));
	}
	
	Rational divide(Rational b) {
		return new Rational(nom.multiply(b.denom), denom.multiply(b.nom));
	}
	
	boolean isZero() {
		return nom.equals(BigInteger.ZERO);
	}
	
	BigInteger trunc() {
		return nom.divide(denom);
	}
}  