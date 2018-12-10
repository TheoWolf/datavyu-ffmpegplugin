package org.datavyu.plugins.examples;


import org.datavyu.plugins.MediaPlayer;
import org.datavyu.plugins.mpv.MpvAwtMediaPlayer;

import javax.swing.*;
import java.io.File;
import java.net.URI;

public class SimpleMpvAwtMediaPlayer {

    public static void main(String[] args) {
        // Define the media file
        URI mediaPath = new File("Nature_30fps_1080p.mp4").toURI();

        // Create the media player using the constructor with File
        MediaPlayer mediaPlayer = new MpvAwtMediaPlayer(mediaPath, new JDialog());

        // Initialize the player
        mediaPlayer.init();

        // Open a JFrame to control the media player through key commands
        new JMediaPlayerControlFrame(mediaPlayer);
    }
}
