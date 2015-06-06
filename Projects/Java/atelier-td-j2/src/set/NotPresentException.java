package set;

import java.lang.annotation.Documented;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * Created by inad on 14/04/15.
 */
public class NotPresentException extends Exception {
    /**
     * Thrown when an element is not present
     * @author inad
     * @version 1.0
     */
    public NotPresentException(Integer i) {
        System.err.println("The integer " + i + " is not present.");
    }

    @Retention(RetentionPolicy.SOURCE)
    @Documented
    public @interface TODO {
        String description() default "default_value";
        int priority() default 5;
    }

    @TODO(description = "Exception handling", priority = 5)
    public void doSomething() {
        /* ... */
    }
}