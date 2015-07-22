/*
                                Camera.h

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*   This file is part of:	freeture
*
*   Copyright:      (C) 2014-2015 Yoan Audureau -- FRIPON-GEOPS-UPSUD
*
*   License:        GNU General Public License
*
*   FreeTure is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*   FreeTure is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*   You should have received a copy of the GNU General Public License
*   along with FreeTure. If not, see <http://www.gnu.org/licenses/>.
*
*   Last modified:      21/01/2015
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/**
* \file    Camera.h
* \author  Yoan Audureau -- FRIPON-GEOPS-UPSUD
* \version 1.0
* \date    13/06/2014
* \brief
*/

#pragma once

#include "config.h"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "ECamBitDepth.h"
#include "Frame.h"

using namespace cv;
using namespace std;

class Camera {

    public :

        /**
        * List connected GigE devices.
        *
        */
        virtual bool listGigeCameras() {return false;};

        /**
        * Open/create a device.
        *
        * @param id Identification number of the camera to create.
        */
        virtual bool createDevice(int id) {return false;};

        /**
        * Get camera name from its ID.
        *
        * @param id Identification number of the camera from which the name is required.
        * @param device The camera's name found.
        * @return Success status to find camera's name.
        */
        virtual bool getDeviceNameById(int id, string &deviceName) {return false;};

        /**
        * Get device's grabbing status.
        *
        * @return Device grabs frames or not.
        */
        virtual bool getStopStatus() {return false;};

        /**
        * Prepare device to grab frames.
        *
        * @return Success status to prepare camera.
        */
        virtual bool grabInitialization() {return false;};

        /**
        * Run acquisition.
        *
        */
        virtual void acqStart() {};

        /**
        * Stop acquisition.
        *
        */
        virtual void acqStop() {};

        /**
        * Close a device and clean resources.
        *
        */
        virtual void grabCleanse() {};

        /**
        * Get a frame from continuous acquisition.
        *
        * @param newFrame New frame's container object.
        * @return Success status to grab a frame.
        */
        virtual bool grabImage(Frame &newFrame) {return false;};

        /**
        * Get a frame from single acquisition.
        *
        * @param newFrame Frame's container object.
        * @param camID Device's identification number from which the single acquisition will be performed.
        * @return Success status to grab a frame.
        */
        virtual bool grabSingleImage(Frame &frame, int camID) {return false;};

        /**
        * Get device's exposure time bounds.
        *
        * @param eMin Return minimum exposure time value.
        * @param eMax Return maximum exposure time value.
        */
        virtual void getExposureBounds(int &eMin, int &eMax) {};

        /**
        * Get device's gain bounds.
        *
        * @param gMin Return minimum gain value.
        * @param gMax Return maximum gain value.
        */
        virtual void getGainBounds(int &gMin, int &gMax) {};

        /**
        * Get device's image format.
        *
        * @param format Return image format.
        * @return Success status to get format.
        */
        virtual bool getPixelFormat(CamBitDepth &format) {return false;};

        /**
        * Get device's frame width.
        *
        * @return Frame's width.
        */
        virtual int getFrameWidth() {return 0;};

        /**
        * Get device's frame height.
        *
        * @return Frame's height.
        */
        virtual int getFrameHeight() {return 0;};

        /**
        * Get device's acquisition frequency.
        *
        * @return Device's fps.
        */
        virtual int getFPS() {return 0;};

        /**
        * Get device's model name.
        *
        * @return Device's model name.
        */
        virtual string getModelName() {return "";};

        /**
        * Get device's gain value.
        *
        * @return Device's gain.
        */
        virtual int getGain() {return 0;};

        /**
        * Get device's exposure time value.
        *
        * @return Device's exposure time.
        */
        virtual int getExposureTime() {return 0;};

        /**
        * Set device's exposure time value.
        *
        * @param value New exposure time value (us).
        * @return Success status to set new exposure time.
        */
        virtual bool setExposureTime(int value)	{return false;};

        /**
        * Set device's gain value.
        *
        * @param value New gain value.
        * @return Success status to set new gain.
        */
        virtual bool setGain(int value) {return false;};

        /**
        * Set device's acquisition frequency.
        *
        * @param value New fps value.
        * @return Success status to set fps.
        */
        virtual bool setFPS(int value) {return false;};

        /**
        * Set device's format.
        *
        * @param format New format.
        * @return Success status to set format.
        */
        virtual bool setPixelFormat(CamBitDepth format) {return false;};

        /**
        * Get data status if a set of directories or videos are used in input.
        *
        * @return If there is still recorded frames to load in input.
        */
        virtual bool getDataSetStatus() {return false;};

        /**
        * Load next data set of frames.
        *
        * @return Success status to load next data set.
        */
        virtual bool loadNextDataSet(string &location) {return true; location = "";};

};
