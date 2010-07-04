package org.openshapa.views.component;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.RenderingHints;
import java.awt.geom.GeneralPath;

import javax.swing.JComponent;

import org.openshapa.models.component.RegionModel;
import org.openshapa.models.component.ViewableModel;
import org.openshapa.util.G2DUtils;


/**
 * This class paints the custom playback region.
 */
public class RegionPainter extends JComponent {

    /** Auto-generated by Eclipse. */
    private static final long serialVersionUID = 3570489696805853386L;

    /** Polygon region for the start marker. */
    private GeneralPath startMarkerPolygon;

    /** Polygon region for the end marker. */
    private GeneralPath endMarkerPolygon;

    /** Region model. */
    private RegionModel regionModel;

    /** Viewable model. */
    private ViewableModel viewableModel;

    /**
     * @return The region model in use.
     */
    public final RegionModel getRegionModel() {
        return regionModel;
    }

    /**
     * @param newRegionModel The new region model to use.
     */
    public final void setRegionModel(final RegionModel newRegionModel) {
        regionModel = newRegionModel;
        repaint();
    }

    /**
     * @param newModel The new viewable model to use.
     */
    public final void setViewableModel(final ViewableModel newModel) {
        viewableModel = newModel;
        repaint();
    }

    /**
     * @return The polygon used to represent the end marker.
     */
    public final GeneralPath getEndMarkerPolygon() {
        return endMarkerPolygon;
    }

    /**
     * @return The polygon used to represent the start marker.
     */
    public final GeneralPath getStartMarkerPolygon() {
        return startMarkerPolygon;
    }

    @Override public final boolean contains(final Point p) {
        return startMarkerPolygon.contains(p) || endMarkerPolygon.contains(p);
    }

    @Override public final boolean contains(final int x, final int y) {
        return startMarkerPolygon != null && startMarkerPolygon.contains(x, y)
            || endMarkerPolygon != null && endMarkerPolygon.contains(x, y);
    }

    private double getXForTime(final long timeInMilliseconds) {
    	final long time = Math.min(Math.max(timeInMilliseconds, viewableModel.getZoomWindowStart()), viewableModel.getZoomWindowEnd());
        final double pixelsPerMillisecond = viewableModel.getIntervalWidth() / viewableModel.getIntervalTime();
        final double dx = (time - viewableModel.getZoomWindowStart()) * pixelsPerMillisecond;
        return regionModel.getPaddingLeft() + dx;
    }
    
    @Override public final void paint(final Graphics g) {
        if ((regionModel == null) || (viewableModel == null)) {
            return;
        }

        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        
        Dimension size = this.getSize();
        
        // If the left region marker is visible, paint the marker
        final long regionStart = regionModel.getRegionStart();
        final long regionEnd = regionModel.getRegionEnd();
        final int paddingTop = regionModel.getPaddingTop();

        final float needleWidth = 1;
        final float regionMarkerWidth = 10;
        final float regionMarkerHeight = 19;
        final float penWidth = 1;
        
        final Color markerFillColor = new Color(15, 135, 0, 100);
        final Color markerOutlineColor = new Color(15, 135, 0);
        final Color outsideRegionFillColor = new Color(63, 63, 63, 100);

        g2d.setStroke(new BasicStroke(penWidth));
        
        // If the left region marker is visible, paint the marker
        if (regionStart >= viewableModel.getZoomWindowStart()) {
            final double xPos = getXForTime(regionModel.getRegionStart());
            startMarkerPolygon = new GeneralPath();
            startMarkerPolygon.moveTo((float) (xPos - regionMarkerWidth - needleWidth), paddingTop);
            startMarkerPolygon.lineTo((float) (xPos - needleWidth), regionMarkerHeight + paddingTop);
            startMarkerPolygon.lineTo((float) (xPos - needleWidth), getSize().height - penWidth);
            startMarkerPolygon.lineTo((float) (xPos - regionMarkerWidth - needleWidth), getSize().height - penWidth);
            startMarkerPolygon.closePath();
            
            g2d.setColor(markerFillColor);
            g2d.fill(startMarkerPolygon);

            g2d.setColor(markerOutlineColor);
            g2d.draw(startMarkerPolygon);
        } else {
        	startMarkerPolygon = new GeneralPath();
        }

        // If the right region marker is visible, paint the marker
        if ((viewableModel.getZoomWindowStart() <= regionEnd) && (regionEnd <= viewableModel.getZoomWindowEnd())) {
            final double xPos = Math.floor(getXForTime(regionModel.getRegionEnd()));
            endMarkerPolygon = new GeneralPath();
            endMarkerPolygon.moveTo((float) (xPos + needleWidth), regionMarkerHeight + paddingTop);
            endMarkerPolygon.lineTo((float) (xPos + regionMarkerWidth + needleWidth), paddingTop);
            endMarkerPolygon.lineTo((float) (xPos + regionMarkerWidth + needleWidth), getSize().height - penWidth);
            endMarkerPolygon.lineTo((float) (xPos + needleWidth), getSize().height - penWidth);
            endMarkerPolygon.closePath();
            
            g2d.setColor(markerFillColor);
            g2d.fill(endMarkerPolygon);

            g2d.setColor(markerOutlineColor);
            g2d.draw(endMarkerPolygon);
        } else {
        	endMarkerPolygon = new GeneralPath();
        }

        /*
         * Check if the selected region is not the maximum viewing window, if it
         * is not the maximum, dim the unplayed regions.
         */
        if (regionStart > 0) {
            final long endTimePos = Math.min(Math.max(regionStart, viewableModel.getZoomWindowStart()), viewableModel.getZoomWindowEnd());

            final double endXPos = getXForTime(endTimePos);
            final double startXPos = regionModel.getPaddingLeft();
            final double x = startXPos;
            final double y = regionMarkerHeight;
            final double width = endXPos - startXPos - needleWidth;
            final double height = size.height;
            
            if (width > 0) {
	            g2d.setColor(outsideRegionFillColor);
	            g2d.fill(G2DUtils.rect(x, y, width, height));
            }
        }

        if (regionEnd < viewableModel.getZoomWindowEnd()) {
            final long startTimePos = Math.min(Math.max(regionEnd, viewableModel.getZoomWindowStart()), viewableModel.getZoomWindowEnd());

            final double startXPos = getXForTime(startTimePos);
            final double endXPos = getXForTime(viewableModel.getZoomWindowEnd());
            final double x = startXPos + needleWidth;
            final double y = regionMarkerHeight;
            final double width = endXPos - startXPos - needleWidth;
            final double height = size.height;

            if (width > 0) {
	            g2d.setColor(outsideRegionFillColor);
	            g2d.fill(G2DUtils.rect(x, y, width, height));
            }
        }
    }
}
