package com.company;

import set.*;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
	// write your code here
        try {
            String num = "";
            String s = "";
            for (int i = 1; i < args.length; i++) {
                BufferedReader f = new BufferedReader(new FileReader(args[i]));
                s = f.readLine();
                // FIXME: read from the files, parse them and use the Set class
                f.close();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace(System.err);
        } catch (IOException e) {
            e.printStackTrace(System.err);
        }
    }
}
