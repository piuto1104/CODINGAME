import java.util.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(); // Number of elements which make up the association table.
        int Q = in.nextInt(); // Number Q of file names to be analyzed.
        HashMap<String,String> table = new HashMap<String, String>();
        for (int i = 0; i < N; i++) {
            String EXT = in.next(); // file extension
            String MT = in.next(); // MIME type.
            table.put(EXT.toLowerCase(), MT);
        }
        in.nextLine();
        for (int i = 0; i < Q; i++) {
            String FNAME = in.nextLine(); // One file name per line.

            //Find the beginning of an extension.
            int extensionIndex = FNAME.lastIndexOf('.');
            if (extensionIndex < 0){
                System.out.println("UNKNOWN");
                continue;
            }

            String type =  FNAME.substring(extensionIndex + 1).toLowerCase();
            if(table.containsKey(type)){
                System.out.println(table.get(type));
            } else {
                System.out.println("UNKNOWN");
            }

        }
    }
}