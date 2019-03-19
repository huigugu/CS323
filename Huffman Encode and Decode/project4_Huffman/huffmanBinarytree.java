package project4_Huffman;

import java.io.*;
import java.util.Scanner;

public class huffmanBinarytree {
	treeNode root;
	linkedList L;
	String charCode[];

	huffmanBinarytree() {
		root = null;
		L = new linkedList();
		charCode = new String[256];
	}

	void constructLL(Scanner in, PrintStream out) {
		out.println("***Below is the ordered linked list***");
		treeNode newNode;
		int p;
		String ch;
		while (in.hasNext()) {
			ch = in.next();
			p = in.nextInt();
			if (ch.charAt(0) == '@') {
				char temp = (char) 32;
				String s = String.valueOf(temp);
				ch = s;
			}
			if (ch.charAt(0) == '#') {
				char temp2 = (char) 10;
				String s2 = String.valueOf(temp2);
				ch = s2;
			}

			newNode = new treeNode(ch, p);
			L.inSertNode(newNode);
			out.println(L.printList());
			// System.out.println(L.printList());
		}

	}

	void constrctTree(PrintStream out) {
		out.println("***below is the tree***");
		// System.out.println("***below is the tree***");
		L.Head = L.Head.next;
		treeNode newNode = null;
		while (L.Head.next != null) {
			String ch = L.Head.chr + L.Head.next.chr;
			int p = L.Head.prob + L.Head.next.prob;
			newNode = new treeNode(ch, p);
			newNode.left = L.Head;
			newNode.right = L.Head.next;
			L.inSertNode(newNode);
			L.Head = L.Head.next.next;
			out.println(L.printList());
			// L.Head.toString();

		}
		root = newNode;
		// System.out.println(root.chr);
	}

	void constructTable(treeNode t, String code, PrintStream out1) {
		if (isLeaf(t)) {
			t.code = code;
			String temp = t.chr;
			char c = temp.charAt(0);
			int index = (int) c;
			charCode[index] = code;
			out1.println(temp + " " + code);

		} else {
			constructTable(t.left, code + "0", out1);
			constructTable(t.right, code + "1", out1);
		}

	}

	void encode(Scanner encodeFile, PrintStream outFile) {
		while (encodeFile.hasNext()) {
			
			String line = encodeFile.nextLine();
			  char ary[] = line.toCharArray();
			  for( int i=0; i<ary.length;i++) {
				  char ch =ary[i];
				  int index =(int)ch;
				  outFile.print(charCode[index]);
			  }
		}
	}
		
	

	void decode(Scanner decodeFile, PrintStream outFile) {
		treeNode spot = root;
		while (decodeFile.hasNext()) {
			String temp = decodeFile.next();
			for (int i = 0; i < temp.length(); i++) {
				char oneBit = temp.charAt(i);
				if (oneBit == '0') {
					spot = spot.left;
				} else if (oneBit == '1') {
					spot = spot.right;
				} else {
					throw new IllegalArgumentException("Invaild input character");
				}
				if (isLeaf(spot)) {
					outFile.print(spot.chr);
					spot = root;
				}
			}
		}

	}

	void userInterface() {
		String nameOrg, nameCompress, nameDecompress;
		char yesNo;
		System.out.println("If you wants to encode a file enter Y else N ");
		Scanner in = new Scanner(System.in);
		String s = in.next();
		yesNo = s.charAt(0);
		while (yesNo == 'Y') {

			System.out.println("Enter the file name to compress");
			nameOrg = in.next();
			nameCompress = nameOrg + "_Compressed.txt";
			nameDecompress = nameOrg + "_DeCompressed.txt";
			// System.out.println(nameCompress);
			try {

				Scanner read = new Scanner(new File(nameOrg));// read data1
				PrintStream en = new PrintStream(new File(nameCompress));// create
				encode(read, en);
				en.close();
				Scanner read2 = new Scanner(new File(nameCompress));
				PrintStream de = new PrintStream(new File(nameDecompress));
				decode(read2, de);
				System.out.println("continues to encode and decode enter Y else N ");
				String s2 = in.next();
				yesNo =s2.charAt(0);
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		System.out.println("Terminated ");
	}

	boolean isLeaf(treeNode newNode) {
		return (newNode.left == null && newNode.right == null);
	}

	void preOrder(treeNode t, PrintStream out2) {

		if (t == null) {
			return;
		} else {
			out2.println(t.printNode());
			preOrder(t.left, out2);
			preOrder(t.right, out2);
		}
	}

	void inOrder(treeNode t, PrintStream out3) {

		if (t == null) {
			return;
		} else {

			inOrder(t.left, out3);
			out3.println(t.printNode());
			inOrder(t.right, out3);
		}
	}

	void postOrder(treeNode t, PrintStream out4) {

		if (t == null) {
			return;
		} else {

			postOrder(t.left, out4);
			postOrder(t.right, out4);
			out4.println(t.printNode());
		}
	}
}
