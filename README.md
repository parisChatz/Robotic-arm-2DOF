# Robotic-Arm-2DOF
PURPOSE

The aim of the thesis is to develop, study and construct a 2 DOF robotic arm that will write numbers from 0 to 9.
Nowadays it is very common for robotic arms to be used in various sectors (eg medicine, industry). This project is for educational reasons and acts as a step to get an idea of how a robotic arm works and is planned.

IMPLEMENTATION

For the robotic arm to work, a microcontroller is needed, in particular we use Arduino Uno microcontroller, which will command how to move the stylus to the end of the arm to design the numbers. In order to move the robotic arm, we used 3 servomotors, the 2 servomotors adjust the angles of the arm axes and the 3rd servomotor raises the stylus. We also used a 7SDU to indicate the numbers that our robotic arm will design.

ANALYSIS OF ALGORITHM WRITING

The algorithm is basically the idea of how the robotic arm will design the numbers from 0 to 9. Originally, since the particular robotic arm writes the numbers in 7SEG format, we got the number 8 as the pattern because the number 8 contains all other combinations from 0 to 9. Then, using inverse kinematics that helped us calculate the degrees of angles Θ1, Θ2, we calculated the degrees of each servomotor and set them in our code .

# Ρομποτικός-βραχίωνας-2ΒΕ
ΣΚΟΠΟΣ

Σκοπός της εργασίας είναι η ανάπτυξη, μελέτη και κατασκευή ενός ρομποτικού βραχίονα 2 DOF ο οποίος θα γράφει αριθμούς από το 0 μέχρι το 9. Στις μέρες μας είναι πολύ συχνό φαινόμενο οι ρομποτικοί βραχίονες να χρησιμοποιούνται σε διάφορους τομείς ( π.χ ιατρική, βιομηχανία). Η κατασκευή είναι για εκπαιδευτικούς λόγους και αποτέλει ένα πάτημα για να πάρει κάποιος μια ιδέα το πως δουλεύει και προγραμματίζεται ένας ρομποτικός βραχίονας.

ΥΛΟΠΟΙΗΣΗ

Για να δουλέψει ο ρομποτικός βραχίονας χρειάζεται έναν μικροελεγκτή, πιο συγκεκριμένα χρησιμοποιούμε μικροελεγκτή Arduino Uno ο οποίος θα δίνει εντολές του πως να κινηθεί η γραφίδα στο άκρο του βραχίωνα για να σχεδιάσει τους αριθμούς. Για να κινηθεί ο ρομποτικός βραχίονας χρησιμοποιήσαμε 3 servomotors,  οι 2 servomotors ρυθμίζουν  τις γωνίες των αξόνων του βραχίονα και ο 3ος servomotor ανεβοκατεβάζει τη γραφίδα.Επίσης χρησιμοποιήσαμε ενα 7SDU για την ένδειξη των αριθμών που θα σχεδιάσει ο ρομποτικός μας βραχίονας.

AΝΑΛΥΣΗ ΑΛΓΟΡΙΘΜΟΥ ΓΡΑΦΗΣ

Ο αλγόριθμος σχεδίασης είναι στην ουσία η σκέψη του πως θα σχεδιάσει ο ρομποτικός βραχίονας τους αριθμούς από το 0 μέχρι το 9. Αρχικά εφόσον ο συγκεκριμένος ρομποτικός βραχίονας που έχουμε κατασκυάσει γράφει τους αριθμους σε μορφή 7TAE, πήραμε σαν μοτίβο τον αριθμό 8, διότι ο αριθμός 8 περιέχει όλους τους υπόλοιπους συνδιασμούς απο το 0 μέχρι το 9. Οπότε ύστερα με τη χρήση εξισώσεων αντίστροφης κινηματικής(inverse kinematics) οι οποίες μας βοήθησαν στον υπολογισμό των μοιρών των γωνιων Θ1,Θ2) υπολογίσαμε τις μοίρες κάθε servomotor και τις ορίσαμε στων κώδικα μας.
