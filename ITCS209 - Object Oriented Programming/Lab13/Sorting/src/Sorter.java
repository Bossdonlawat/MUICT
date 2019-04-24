import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Sorter {
	
	private static ArrayList<String> word;
	
	public static ArrayList<String> Loaddata(String filename) {
		word = new ArrayList<String>();
		File file = new File(filename);
		Scanner sc;

		try {
			sc = new Scanner(file);
			while(sc.hasNextLine()) {
				String[] part = sc.nextLine().split("\\s");
				for(int i=0; i<part.length;i++) {
					word.add(part[i]);
				}	
			}
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		return word;
	}
	
	public static void Printdata(ArrayList<String> word) {
		System.out.print("[" + word.get(0));

		for(int i=1;i<word.size();i++)  {
			System.out.print(", "+ word.get(i));
		}

		System.out.println("]");
	}
	
	public static void Sortdata(ArrayList<String> word) {
		
		int index;
		for(int j=1;j<word.size();j++) {
			String a = word.get(j);
			index = j;
			for(int k=j-1;k>=0;k--) {
				if(a.compareTo(word.get(k)) > 0) {
					index = k;
				}
			}
			word.add(index, a);
			word.remove(j+1);
			System.out.print("Pass"+j + ": ");
			Printdata(word);	
		}
				
	}
	
    public static void Merged(String sorted[], int left, int mid, int right) 
    { 
    	int inL = mid - left;
    	int inR = right - mid;
  
    	String L[] = new String [inL];
    	String R[] = new String [inR];
  
    	for (int i=0; i<inL; ++i) {
    		L[i] = sorted[left + i];
    	}

    	for (int j=0; j<inR; ++j) {
    		R[j] = sorted[mid + j];
    	}
        
    	int i = 0, j = 0;
  
    	int k = left;
    	while (i < inL && j < inR) {
    		if (L[i].compareTo(R[j])>0) {
    			sorted[k++] = L[i++];
    		}
    		else {
    			sorted[k++] = R[j++];
    		}
    	}
  
    	while (i < inL) {
    		sorted[k++] = L[i++];
    	}
  
    	while (j < inR) {
    		sorted[k++] = R[j++];
    	}
    } 
  
    public static void Mergesort(String sorted[], int left, int right) 
    { 
    	if (right-left>1) {
    		int mid = (left+right)/2;

    		Mergesort(sorted, left, mid);
    		Mergesort(sorted , mid, right);
    		Merged(sorted, left, mid, right);
    	}
    } 
    
    
	public static void main(String[] args) {
		Sorter.word = Sorter.Loaddata("unsorted.txt");
		System.out.print("Original: ");
		Printdata(word);
		
		/* Bonus */
		String[] sorted = new String[word.size()];
		for(int i=0;i<word.size();i++)
			sorted[i] = word.get(i);

		Mergesort(sorted, 0, sorted.length);
		
		System.out.print("Sorted: [" + sorted[0]);
		int i=1;

		while(i<10) {
			System.out.print( ", " + sorted[i]);
			i++;
		}

		System.out.println("]");
	}
	
}
