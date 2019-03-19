package project4_Huffman;

import java.io.PrintStream;
import java.util.Scanner;

public class linkedList {
	treeNode Head;

	linkedList() {
		Head = new treeNode("Dummy", 0);
	}

	treeNode findSpot(treeNode newNode) {
		treeNode spot = Head;
		while (spot.next != null && spot.next.prob < newNode.prob) {
			spot = spot.next;
		}
		return spot;
	}

	void inSertNode(treeNode nn) {
		treeNode spot = findSpot(nn);
		nn.next = spot.next;
		spot.next = nn;
	}

	public String toString() {
		treeNode temp = Head;
		String s = "listHead-->";
		String s1 = "";
		while (temp != null) {
			if (temp.next == null) {
				s1 = "null)-->";
			} else {
				s1 = temp.next.chr + ")-->";
			}
			s = s + "(" + temp.chr + ", " + temp.prob + ", " + s1;
			temp = temp.next;
			;
		}
		s = s + "Null";
		return s;
	}

	void constructLL(Scanner in, PrintStream out) {

		treeNode newNode;
		int p;
		String ch;
		while (in.hasNext()) {
			ch = in.next();
			p = in.nextInt();
			newNode = new treeNode(ch, p);
			inSertNode(newNode);
			out.println(printList());
			System.out.println(printList());
		}

	}

	public String printList() {
		return this.toString();
	}

}
