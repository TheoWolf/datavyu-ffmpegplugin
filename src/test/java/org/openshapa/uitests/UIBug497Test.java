package org.openshapa.uitests;

import java.awt.event.KeyEvent;

import org.fest.swing.core.KeyPressInfo;
import org.fest.swing.core.matcher.JTextComponentMatcher;
import org.fest.swing.fixture.JLabelFixture;
import org.fest.swing.fixture.JPanelFixture;
import org.fest.swing.fixture.JTextComponentFixture;
import org.fest.swing.util.Platform;

import org.openshapa.util.UIUtils;

import org.testng.Assert;

import org.testng.annotations.Test;


/**
 * Bug 497: Allows you to paste values greate than max integer and also multiple
 * "-". Example: 999999999999999999-239839231-2398392310820831 Pressing -ve on
 * such a number results in unpredictable behaviour.
 */
public final class UIBug497Test extends OpenSHAPATestClass {

    /**
     * Bug 497 integer test.
     */
    @Test public void testBug497Integer() {
        System.err.println(new Exception().getStackTrace()[0].getMethodName());

        String varName = "i";
        String varType = "INTEGER";
        String varRadio = varType.toLowerCase() + "TypeButton";

        String testInput = "999999999999999999-239839231-2398392310820831";
        String expectedTestOutput = "2999999999999999999";

        // 1. Get spreadsheet
        spreadsheet = mainFrameFixture.getSpreadsheet();

        // 2. Create new TEXT variable
        mainFrameFixture.createNewVariable(varName, varRadio);

        // 3. Create cell, paste text
        // a. Create cell
        spreadsheet.column(0).click();
        mainFrameFixture.clickMenuItemWithPath("Spreadsheet", "New Cell");

        // b. Paste text
        UIUtils.setClipboard(testInput);

        JTextComponentFixture cell = mainFrameFixture.textBox(
                JTextComponentMatcher.withText("<val>"));
        cell.click();
        cell.pressAndReleaseKey(KeyPressInfo.keyCode(KeyEvent.VK_V).modifiers(
                Platform.controlOrCommandMask()));

        // c. Check text
        Assert.assertEquals(cell.text(), expectedTestOutput);
    }

    /**
     * Bug 497 float test.
     */
    @Test public void testBug497Float() {
        System.err.println(new Exception().getStackTrace()[0].getMethodName());

        String varName = "f";
        String varType = "FLOAT";
        String varRadio = varType.toLowerCase() + "TypeButton";

        String testInput = "999999999999999999-239839231-2398392310820831";
        String expectedTestOutput = "999999999999999.0";

        // 1. Get spreadsheet
        spreadsheet = mainFrameFixture.getSpreadsheet();

        // 2. Create new TEXT variable
        mainFrameFixture.createNewVariable(varName, varRadio);

        // 3. Create cell, paste text
        // a. Create cell
        spreadsheet.column(0).click();
        mainFrameFixture.clickMenuItemWithPath("Spreadsheet", "New Cell");

        // b. Paste text
        UIUtils.setClipboard(testInput);

        JTextComponentFixture cell = mainFrameFixture.textBox(
                JTextComponentMatcher.withText("<val>"));
        cell.click();
        cell.pressAndReleaseKey(KeyPressInfo.keyCode(KeyEvent.VK_V).modifiers(
                Platform.controlOrCommandMask()));

        // c. Check text
        Assert.assertEquals(cell.text(), expectedTestOutput);
    }
}
