package set;

/**
 * Created by inad on 14/04/15.
 */
public interface IComparable {
    public boolean lessThan(IComparable obj);

    @Override
    public boolean equals(Object o);
}
