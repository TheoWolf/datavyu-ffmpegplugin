package org.datavyu.plugins.ffplayer;

import java.io.IOException;

/**
 * This interface associates time to a stream. It provides the start time, 
 * end time, duration, current time, seek of a time, and a speed. The idea is 
 * to have same interface as for a stream but with methods that control time
 * within that stream. The unit of time is seconds.
 * 
 * @author Florian Raudies, Mountain View, CA.
 *
 */
public interface TimeStream {

	/**
	 * Get the start time of the stream. Typically that will be 0.0.
	 * 
	 * @return The start time in seconds.
	 */
	public double getStartTime();

	/**
	 * Get the end time of the stream.
	 * 
	 * @return The end time in seconds.
	 */
	public double getEndTime();

	/**
	 * Get the duration of the stream.
	 * 
	 * @return The duration in seconds.
	 */
	public double getDuration();

	/**
	 * Get the current time position within the stream.
	 * 
	 * @return The current time in seconds.
	 */
	public double getCurrentTime();

	/**
	 * Seek a time within the stream.
	 * 
	 * @param time The time point to seek in seconds.
	 * 
	 * @throws IndexOutOfBoundsException if the time is outside the range of 
	 * start time and end time.
	 */
	public void seek(double time) throws IndexOutOfBoundsException; // set time to continue play back

	/**
	 * Set the play back speed as multiple of the native play back and also 
	 * allows to control the direction of play back. For instance, a value of 
	 * -1x plays the stream backwards if the underlying class implements such 
	 * play back.
	 * 
	 * @param speed The speed, e.g. 0.5x or -4x.
	 * 
	 * @throws IndexOutOfBoundsException A stream may not be played back 
	 * arbitrarily fast. If the implementing class does not support a value it 
	 * throws this exception.
	 */
	public void setSpeed(float speed) throws IndexOutOfBoundsException; // play back speed for the movie
	
	/**
	 * Rewinds the stream to the starting position. In forward play back the 
	 * starting position is the start time. In backward play back the starting
	 * position is the end time.
	 */
	public void reset();
	
	/**
	 * Closes the stream and frees all associated resources.
	 * 
	 * @throws IOException if the resources cannot be cleanly shut down.
	 */
	public void close() throws IOException;
}
