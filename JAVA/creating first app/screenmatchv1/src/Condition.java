public class Condition {
    public static void main(String[] args) {
        int launchYear = 2006;
        String tplans = "plus";
        boolean plansCover = true;
        double rating = 7.400000000000001;
        if (launchYear >= 2022) {
            System.out.println("A launch movie that isa good choose to watch");
        } else {
            System.out.println("Old movie that's a good try");
        }

        if (!plansCover && !tplans.equals("plus")) {
            System.out.println("Need to buy alloc");
        } else {
            System.out.println("Allowed movie");
        }

    }
}


