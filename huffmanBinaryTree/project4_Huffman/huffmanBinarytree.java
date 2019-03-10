package project4_Huffman;

import java.io.*;
import java.util.Scanner;

public class huffmanBinarytree {
	treeNode root;
	linkedList L;

	huffmanBinarytree() {
		root = null;
		L = new linkedList();
	}

	void constructLL(Scanner in, PrintStream out) {
		out.println("***Below is the ordered linked list***");
		treeNode newNode;
		int p;
		String ch;
		while (in.hasNext()) {
			ch = in.next();
			p = in.nextInt();
			newNode = new treeNode(ch, p);
			L.inSertNode(newNode);
			out.println(L.printList());
			System.out.println(L.printList());
		}

	}

	void constrctTree(PrintStream out) {
		out.println("***below is the tree***");
		System.out.println("***below is the tree***");
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
