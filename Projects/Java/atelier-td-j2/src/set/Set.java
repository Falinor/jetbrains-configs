package set;

import java.util.ArrayList;

/**
 * Created by inad on 14/04/15.
 */
public class Set implements IComparable {
    ArrayList<Integer> set = new ArrayList<>();

    public Set() { }

    /**
    ** Add the Integer i only if this one is not already present in the ArrayList
    **/
    public void insert(Integer i) {
        for (Integer j : set) {
            if (i.equals(j)) {
                return;
            }
        }
        this.set.add(i);
    }

    /**
    ** Return true if the Integer i is present
    **/
    public boolean has(Integer i) {
        for (Integer j : set) {
            if (i.equals(j)) {
                return true;
            }
        }
        return false;
    }

    /**
    ** Return true if the ArrayList is empty
    **/
    public boolean isEmpty() {
        if (this.set.isEmpty())
            return true;
        return false;
    }

    /**
     *
     * @return The size of the ArrayList
     */
    public int size() {
        return this.set.size();

    }

    public static Set intersection(Set a, Set b) {
        Set s = new Set();
        for (Integer i : a) {
            for (Integer j : b) {
                if (i.equals(j)) {
                    s.insert(i);
                }
            }
        }
        return s;
    }

    public static Set union(Set a, Set b) {
        Set s = new Set();
        for (Integer i : a.set) {
            s.insert(i);
        }
        for (Integer j : b.set) {
            s.insert(j);
        }
        return s;
    }

    public void remove(Integer i) throws NotPresentException {
        if (!this.set.remove(i))
            throw new NotPresentException(i);
    }

    public boolean lessThan(Set s) {
        for (Integer j : s.set)
            for (Integer i : this.set)
                if (i >= j)
                    return false;
        return true;
    }

    public boolean equals(Set s) {
        for (Integer i : this.set)
            for (Integer j : s.set)
                if (!i.equals(j))
                    return false;
        return true;
    }
}