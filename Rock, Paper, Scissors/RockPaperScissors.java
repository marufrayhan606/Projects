
import java.util.Random;
import java.util.Scanner;

public class RockPaperScissors {

    public static void main(String[] args) {
        Random random = new Random();
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        System.out.println("***********************************");
        System.out.println("*        Rock Paper Scissor       *");
        System.out.println("***********************************");
        System.out.println();
        System.out.println("Press One   ('1') to select Rock");
        System.out.println("Press Two   ('2') to select Paper");
        System.out.println("Press Three ('3') to select Scissor");
        System.out.println("Press Zero  ('0') to Exit");
        System.out.println("###################################");
        int player, playerScore = 0, computerScore = 0, Round = 1;
        do {
            System.out.println("Round : " + Round);
            int computer = random.nextInt(3) + 1;
            player = scanner.nextInt();

            switch (player) {
                case 1 ->
                    System.out.println("Played Rock");
                case 2 ->
                    System.out.println("Played Paper");
                case 3 ->
                    System.out.println("Played Scissor");
            }

            if (computer != player) {

                switch (computer) {
                    case 1 -> {
                        if (player == 2) {
                            playerScore++;
                            System.out.println("Won");
                        } else if (player == 3) {
                            computerScore++;
                            System.out.println("Lost");
                        }
                    }

                    case 2 -> {
                        if (player == 3) {
                            playerScore++;
                            System.out.println("Won");
                        } else if (player == 1) {
                            computerScore++;
                            System.out.println("Lost");
                        }
                    }

                    case 3 -> {
                        if (player == 1) {
                            playerScore++;
                            System.out.println("Won");
                        } else if (player == 2) {
                            computerScore++;
                            System.out.println("Lost");
                        }
                    }

                }
            } else {
                System.out.println("Draw !!!");
            }
            System.out.println();
            Round++;
        } while (player != 0);

        System.out.println("**********************************");
        if (playerScore > computerScore) {
            System.out.println("You Won the Match by " + (playerScore - computerScore) + " points");

        } else if (computerScore > playerScore) {
            System.out.println("You Lost the Match by " + (computerScore - playerScore) + " points");
        } else {
            System.out.println("Match Drawn");
        }
        System.out.println("**********************************");

    }
}
