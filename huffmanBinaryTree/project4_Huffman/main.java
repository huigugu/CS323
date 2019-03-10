package project4_Huffman;

import java.io.*;
import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		File inFile;
		inFile = new File(args[0]);
		PrintStream outFile1 = null, outFile2 = null, outFile3 = null, outFile4 = null;
		Scanner read = null;
		try {
			read = new Scanner(inFile);
			outFile1 = new PrintStream(args[1]);
			outFile2 = new PrintStream(args[2]);
			outFile3 = new PrintStream(args[3]);
			outFile4 = new PrintStream(args[4]);
			huffmanBinarytree tree = new huffmanBinarytree();
			tree.constructLL(read, outFile1);
			tree.constrctTree(outFile1);
			outFile2.println("Preorder:");
			tree.preOrder(tree.root, outFile2);
			outFile3.println("Inorder:");
			tree.inOrder(tree.root, outFile3);
			outFile4.println("Postorder:");
			tree.postOrder(tree.root, outFile4);

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		read.close();
		outFile1.close();
		outFile2.close();
		outFile3.close();
		outFile4.close();

	}

}
