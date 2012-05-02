/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.openshapa.controllers;

import com.usermetrix.jclient.Logger;
import org.openshapa.OpenSHAPA;

import com.usermetrix.jclient.UserMetrix;
import javax.swing.undo.UndoableEdit;
import org.openshapa.models.db.Cell;
import org.openshapa.undoableedits.ChangeCellEdit;
import org.openshapa.undoableedits.ChangeOffsetCellEdit;

/**
 * Controller for setting the stop time (offset) of a new cell.
 */
public final class SetNewCellStopTimeC {

    /** The logger for this class. */
    private static Logger LOGGER = UserMetrix.getLogger(SetNewCellStopTimeC.class);

    /**
     * Sets the stop time of the last cell that was created.
     * 
     * @param milliseconds The number of milliseconds since the origin of the
     * spreadsheet to set the stop time for.
     */
    public SetNewCellStopTimeC(final long milliseconds) {
        LOGGER.event("set new cell offset");

        Cell c = OpenSHAPA.getProjectController().getLastCreatedCell();
        // record the effect
        UndoableEdit edit = new ChangeOffsetCellEdit(c, c.getOffset(), milliseconds, ChangeCellEdit.Granularity.FINEGRAINED);
        OpenSHAPA.getView().getUndoSupport().postEdit(edit);

        c.setOffset(milliseconds);
    }
}
