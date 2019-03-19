package project4_Huffman;

public class treeNode {
	String chr;
	int prob;
	treeNode next;
	treeNode right, left;
	String code;

	treeNode(String ch, int pro) {
		next = null;
		right = null;
		left = null;
		code = "";
		prob = pro;
		chr = ch;
	}

	String printNode() {
		// given a node, T, print T’s chStr, T’s prob, T’s next chStr,
		// T’s left’s chStr,T ight’s chStr
		String start = "(" + chr + ", " + prob + ", " + ", " + code+ ", ";
		if (next == null) {
			start += "null,";
		} else {
			start += next.chr + ",";
		}
		if (left == null) {
			start += "null,";
		} else {
			start += left.chr + ",";
		}
		if (right == null) {
			start += "null,";
		} else {
			start += right.chr;
		}
		start = start + ")";
		return start;
	}
}
