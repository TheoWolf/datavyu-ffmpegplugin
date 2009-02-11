package au.com.nicta.openshapa.views.discrete;

import au.com.nicta.openshapa.db.DataCell;
import au.com.nicta.openshapa.db.Matrix;
import au.com.nicta.openshapa.db.SystemErrorException;
import java.util.Vector;
import javax.swing.JLabel;
import org.apache.log4j.Logger;

/**
 * Label view of the Matrix (database cell) data.
 *
 * @author swhitcher
*/
public class MatrixViewLabel extends SpreadsheetPanel {

    /** The parent cell for this JPanel. */
    private DataCell parentCell = null;

    /** The data views used for each of the arguments. */
    private Vector<DataValueView> argViews;

    /** The logger for MatrixViewLabel. */
    private static Logger logger = Logger.getLogger(MatrixViewLabel.class);

    /**
     * Creates a new instance of MatrixViewLabel.
     *
     * @param m The Matrix to display.
    */
    public MatrixViewLabel(final DataCell c, final Matrix m) {
        super();
        parentCell = c;
        argViews = new Vector<DataValueView>();
        setMatrix(m);
    }

    /**
     * Sets the matrix that this MatrixView will represent.
     *
     * @param m The Matrix to display.
     */
    public final void setMatrix(final Matrix m) {
        try {
            // If this matrixView does not contain any components build up
            // view representations for each of the arguments.
            if (m != null && getComponentCount() == 0) {               
                // For each of the matrix arguments, build a view representation
                for (int i = 0; i < m.getNumArgs(); i++) {
                    argViews.add(DataValueViewFactory.build(parentCell, m, i));
                }
            }
        } catch (SystemErrorException e) {
            logger.error("Unable to set Matrix for MatrixViewLabel.", e);
        }

        // If this matrixView does not contain any components. Insert the
        // components for each of the view repsentations.
        if (getComponentCount() == 0) {
            // If we have more than one argument in the matrix - then we need to
            // stack in some additional labels.
            if (argViews.size() > 1) {
                JLabel label = new JLabel("(");
                this.add(label);
            }

            // Build the visual representation of this matrix.
            for (int i = 0; i < argViews.size(); i++) {
                DataValueView dv = argViews.get(i);

                if (dv != null) {
                    this.add(dv);
                }

                if (argViews.size() > 1 && i < (argViews.size() - 1)) {
                    this.add(new JLabel(","));
                }
            }

            // If we have more than one argument in the matrix - then we need to
            // stack in some additional labels.
            if (argViews.size() > 1) {
                this.add(new JLabel(")"));
            }

        // The matrixView does not contain components, alter the contents of
        // what already exists.
        } else {
            for (int i = 0; i < argViews.size(); i++) {
                argViews.get(i).setValue(parentCell, m, i);
            }
        }

        //this.setBorder(BorderFactory.createEtchedBorder());
        this.repaint();
    }
}