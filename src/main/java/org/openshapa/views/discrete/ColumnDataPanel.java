package org.openshapa.views.discrete;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.KeyEvent;
import javax.swing.BorderFactory;

/**
 * ColumnDataPanel panel that contains the SpreadsheetCell panels.
 */
public class ColumnDataPanel extends SpreadsheetElementPanel {

    /**
     * Creates a new ColumnDataPanel.
     */
    public ColumnDataPanel() {
        super();

        setMaximumSize(new Dimension(Integer.MAX_VALUE, Integer.MAX_VALUE));
        setLayout(null);
        this.setBackground(Color.LIGHT_GRAY);
        setBorder(BorderFactory.createMatteBorder(0, 0, 1, 1, Color.BLACK));
    }

    /**
     * The action to invoke when a key is released on the keyboard.
     *
     * @param ke The key event that triggered this action.
     */
    @Override
    public void keyReleased(KeyEvent ke) {
        Component components[] = this.getComponents();
        for (int i = 0; i < this.getComponentCount(); i++) {
            if (components[i].isFocusOwner()) {
                if (ke.getKeyCode() == KeyEvent.VK_UP && i > 0) {
                    components[i - 1].requestFocus();
                }

                if (ke.getKeyCode() == KeyEvent.VK_DOWN && (i + 1) < this.getComponentCount()) {
                    components[i + 1].requestFocus();
                }
            }
        }
    }
}
