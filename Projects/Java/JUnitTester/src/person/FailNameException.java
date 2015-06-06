package person;

/**
 * Created by inad on 14/04/15.
 */
public class FailNameException extends Exception {
    public FailNameException() {
        System.err.println("This name is invalid");
    }
}
