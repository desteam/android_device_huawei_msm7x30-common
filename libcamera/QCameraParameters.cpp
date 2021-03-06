/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#define LOG_TAG "QCameraParameters"

#include <string.h>
#include <stdlib.h>
#include "QCameraParameters.h"

const char QCameraParameters::KEY_SUPPORTED_HFR_SIZES[] = "hfr-size-values";
const char QCameraParameters::KEY_PREVIEW_FRAME_RATE_MODE[] = "preview-frame-rate-mode";
const char QCameraParameters::KEY_SUPPORTED_PREVIEW_FRAME_RATE_MODES[] = "preview-frame-rate-modes";
const char QCameraParameters::KEY_PREVIEW_FRAME_RATE_AUTO_MODE[] = "frame-rate-auto";
const char QCameraParameters::KEY_PREVIEW_FRAME_RATE_FIXED_MODE[] = "frame-rate-fixed";
const char QCameraParameters::KEY_TOUCH_AF_AEC[] = "touch-af-aec";
const char QCameraParameters::KEY_SUPPORTED_TOUCH_AF_AEC[] = "touch-af-aec-values";
const char QCameraParameters::KEY_TOUCH_INDEX_AEC[] = "touch-index-aec";
const char QCameraParameters::KEY_TOUCH_INDEX_AF[] = "touch-index-af";
const char QCameraParameters::KEY_SCENE_DETECT[] = "scene-detect";
const char QCameraParameters::KEY_SUPPORTED_SCENE_DETECT[] = "scene-detect-values";
#ifndef HAVE_ISO
const char QCameraParameters::KEY_ISO_MODE[] = "iso";
const char QCameraParameters::KEY_SUPPORTED_ISO_MODES[] = "iso-values";
#endif
const char QCameraParameters::KEY_LENSSHADE[] = "lensshade";
const char QCameraParameters::KEY_SUPPORTED_LENSSHADE_MODES[] = "lensshade-values";
#ifdef SAMSUNG_CAMERA_LEGACY
const char QCameraParameters::KEY_AUTO_EXPOSURE[] = "metering";
#else
const char QCameraParameters::KEY_AUTO_EXPOSURE[] = "auto-exposure";
#endif
const char QCameraParameters::KEY_SUPPORTED_AUTO_EXPOSURE[] = "auto-exposure-values";
const char QCameraParameters::KEY_DENOISE[] = "denoise";
const char QCameraParameters::KEY_SUPPORTED_DENOISE[] = "denoise-values";
const char QCameraParameters::KEY_SELECTABLE_ZONE_AF[] = "selectable-zone-af";
const char QCameraParameters::KEY_SUPPORTED_SELECTABLE_ZONE_AF[] = "selectable-zone-af-values";
const char QCameraParameters::KEY_FACE_DETECTION[] = "face-detection";
const char QCameraParameters::KEY_SUPPORTED_FACE_DETECTION[] = "face-detection-values";
const char QCameraParameters::KEY_MEMORY_COLOR_ENHANCEMENT[] = "mce";
const char QCameraParameters::KEY_SUPPORTED_MEM_COLOR_ENHANCE_MODES[] = "mce-values";
const char QCameraParameters::KEY_VIDEO_HIGH_FRAME_RATE[] = "video-hfr";
const char QCameraParameters::KEY_SUPPORTED_VIDEO_HIGH_FRAME_RATE_MODES[] = "video-hfr-values";
const char QCameraParameters::KEY_REDEYE_REDUCTION[] = "redeye-reduction";
const char QCameraParameters::KEY_SUPPORTED_REDEYE_REDUCTION[] = "redeye-reduction-values";
const char QCameraParameters::KEY_HIGH_DYNAMIC_RANGE_IMAGING[] = "hdr";
const char QCameraParameters::KEY_SUPPORTED_HDR_IMAGING_MODES[] = "hdr-values";
const char QCameraParameters::KEY_ZSL[] = "zsl";
const char QCameraParameters::KEY_SUPPORTED_ZSL_MODES[] = "zsl-values";
const char QCameraParameters::KEY_CAMERA_MODE[] = "camera-mode";
const char QCameraParameters::KEY_POWER_MODE[] = "power-mode";
const char QCameraParameters::KEY_POWER_MODE_SUPPORTED[] = "power-mode-supported";
const char QCameraParameters::WHITE_BALANCE_MANUAL_CCT[] = "manual-cct";
const char QCameraParameters::EFFECT_EMBOSS[] = "emboss";
const char QCameraParameters::EFFECT_SKETCH[] = "sketch";
const char QCameraParameters::EFFECT_NEON[] = "neon";

// Values for auto exposure settings.
const char QCameraParameters::TOUCH_AF_AEC_OFF[] = "touch-off";
const char QCameraParameters::TOUCH_AF_AEC_ON[] = "touch-on";
const char QCameraParameters::SCENE_MODE_ASD[] = "asd";   // corresponds to CAMERA_BESTSHOT_AUTO in HAL
#ifdef SAMSUNG_CAMERA_LEGACY
const char QCameraParameters::SCENE_MODE_BACKLIGHT[] = "back-light";
#else
const char QCameraParameters::SCENE_MODE_BACKLIGHT[] = "backlight";
#endif
const char QCameraParameters::SCENE_MODE_FLOWERS[] = "flowers";
const char QCameraParameters::SCENE_MODE_AR[] = "AR";

// Values for auto scene detection settings.
const char QCameraParameters::SCENE_DETECT_OFF[] = "off";
const char QCameraParameters::SCENE_DETECT_ON[] = "on";
const char QCameraParameters::PIXEL_FORMAT_YUV420SP_ADRENO[] = "yuv420sp-adreno";
const char QCameraParameters::PIXEL_FORMAT_RAW[] = "raw";
const char QCameraParameters::PIXEL_FORMAT_YV12[] = "yuv420p";
const char QCameraParameters::PIXEL_FORMAT_NV12[] = "nv12";
const char QCameraParameters::FOCUS_MODE_MANUAL_POSITION[] = "manual";
const char QCameraParameters::FOCUS_MODE_NORMAL[] = "normal";


const char QCameraParameters::KEY_SKIN_TONE_ENHANCEMENT[] = "skinToneEnhancement";
const char QCameraParameters::KEY_SUPPORTED_SKIN_TONE_ENHANCEMENT_MODES[] = "skinToneEnhancement-values";

// Values for ISO Settings
const char QCameraParameters::ISO_AUTO[] = "auto";
const char QCameraParameters::ISO_HJR[] = "ISO_HJR";
const char QCameraParameters::ISO_100[] = "ISO100";
const char QCameraParameters::ISO_200[] = "ISO200";
const char QCameraParameters::ISO_400[] = "ISO400";
const char QCameraParameters::ISO_800[] = "ISO800";
const char QCameraParameters::ISO_1600[] = "ISO1600";
const char QCameraParameters::ISO_3200[] = "ISO3200";
const char QCameraParameters::ISO_6400[] = "ISO6400";

 //Values for Lens Shading
const char QCameraParameters::LENSSHADE_ENABLE[] = "enable";
const char QCameraParameters::LENSSHADE_DISABLE[] = "disable";

// Values for auto exposure settings.
const char QCameraParameters::AUTO_EXPOSURE_FRAME_AVG[] = "frame-average";
const char QCameraParameters::AUTO_EXPOSURE_CENTER_WEIGHTED[] = "center-weighted";
const char QCameraParameters::AUTO_EXPOSURE_SPOT_METERING[] = "spot-metering";

const char QCameraParameters::KEY_GPS_LATITUDE_REF[] = "gps-latitude-ref";
const char QCameraParameters::KEY_GPS_LONGITUDE_REF[] = "gps-longitude-ref";
const char QCameraParameters::KEY_GPS_ALTITUDE_REF[] = "gps-altitude-ref";
const char QCameraParameters::KEY_GPS_STATUS[] = "gps-status";
const char QCameraParameters::KEY_EXIF_DATETIME[] = "exif-datetime";

const char QCameraParameters::KEY_HISTOGRAM[] = "histogram";
const char QCameraParameters::KEY_SUPPORTED_HISTOGRAM_MODES[] = "histogram-values";
//Values for Histogram Shading
const char QCameraParameters::HISTOGRAM_ENABLE[] = "enable";
const char QCameraParameters::HISTOGRAM_DISABLE[] = "disable";

//Values for Skin Tone Enhancement Modes
const char QCameraParameters::SKIN_TONE_ENHANCEMENT_ENABLE[] = "enable";
const char QCameraParameters::SKIN_TONE_ENHANCEMENT_DISABLE[] = "disable";

const char QCameraParameters::KEY_SHARPNESS[] = "sharpness";
const char QCameraParameters::KEY_MAX_SHARPNESS[] = "max-sharpness";
const char QCameraParameters::KEY_CONTRAST[] = "contrast";
const char QCameraParameters::KEY_MAX_CONTRAST[] = "max-contrast";
const char QCameraParameters::KEY_SATURATION[] = "saturation";
const char QCameraParameters::KEY_MAX_SATURATION[] = "max-saturation";

//Values for DENOISE
const char QCameraParameters::DENOISE_OFF[] = "denoise-off";
const char QCameraParameters::DENOISE_ON[] = "denoise-on";
// Values for selectable zone af Settings
const char QCameraParameters::SELECTABLE_ZONE_AF_AUTO[] = "auto";
const char QCameraParameters::SELECTABLE_ZONE_AF_SPOT_METERING[] = "spot-metering";
const char QCameraParameters::SELECTABLE_ZONE_AF_CENTER_WEIGHTED[] = "center-weighted";
const char QCameraParameters::SELECTABLE_ZONE_AF_FRAME_AVERAGE[] = "frame-average";

// Values for Face Detection settings.
const char QCameraParameters::FACE_DETECTION_OFF[] = "off";
const char QCameraParameters::FACE_DETECTION_ON[] = "on";

// Values for MCE settings.
const char QCameraParameters::MCE_ENABLE[] = "enable";
const char QCameraParameters::MCE_DISABLE[] = "disable";

// Values for HFR settings.
const char QCameraParameters::VIDEO_HFR_OFF[] = "off";
const char QCameraParameters::VIDEO_HFR_2X[] = "60";
const char QCameraParameters::VIDEO_HFR_3X[] = "90";
const char QCameraParameters::VIDEO_HFR_4X[] = "120";

// Values for Redeye Reduction settings.
const char QCameraParameters::REDEYE_REDUCTION_ENABLE[] = "enable";
const char QCameraParameters::REDEYE_REDUCTION_DISABLE[] = "disable";
// Values for HDR settings.
const char QCameraParameters::HDR_ENABLE[] = "enable";
const char QCameraParameters::HDR_DISABLE[] = "disable";

// Values for ZSL settings.
const char QCameraParameters::ZSL_OFF[] = "off";
const char QCameraParameters::ZSL_ON[] = "on";

// Values for HDR Bracketing settings.
const char QCameraParameters::AE_BRACKET_HDR_OFF[] = "Off";
const char QCameraParameters::AE_BRACKET_HDR[] = "HDR";
const char QCameraParameters::AE_BRACKET[] = "AE-Bracket";

const char QCameraParameters::LOW_POWER[] = "Low_Power";
const char QCameraParameters::NORMAL_POWER[] = "Normal_Power";

#if defined(QCOM_HARDWARE) && defined(SAMSUNG_CAMERA_LEGACY)
const char QCameraParameters::FOCUS_MODE_FACEDETECT[] = "facedetect";
const char QCameraParameters::FOCUS_MODE_TOUCHAF[] = "touchaf";
const char QCameraParameters::ISO_50[] = "ISO50";
const char QCameraParameters::KEY_ANTI_SHAKE_MODE[] = "antishake";
const char QCameraParameters::KEY_AUTO_CONTRAST[] = "auto-contrast";
const char QCameraParameters::KEY_BEAUTY_MODE[] = "beauty";
const char QCameraParameters::KEY_BLUR_MODE[] = "blur";
const char QCameraParameters::KEY_VINTAGE_MODE[] = "vintagemode";
const char QCameraParameters::KEY_WDR_MODE[] = "wdr";
const char QCameraParameters::VINTAGE_MODE_BNW[] = "bnw";
const char QCameraParameters::VINTAGE_MODE_COOL[] = "cool";
const char QCameraParameters::VINTAGE_MODE_NORMAL[] = "normal";
const char QCameraParameters::VINTAGE_MODE_OFF[] = "off";
const char QCameraParameters::VINTAGE_MODE_WARM[] = "warm";
const char QCameraParameters::SCENE_MODE_DAWN[] = "dusk-dawn";
const char QCameraParameters::SCENE_MODE_DUSKDAWN[] = "dusk-dawn";
const char QCameraParameters::SCENE_MODE_FALL[] = "fall-color";
const char QCameraParameters::SCENE_MODE_FALL_COLOR[] = "fall-color";
const char QCameraParameters::SCENE_MODE_TEXT[] = "text";
#endif

static const char* portrait = "portrait";
static const char* landscape = "landscape";

int QCameraParameters::getOrientation() const
{
    const char* orientation = get("orientation");
    if (orientation && !strcmp(orientation, portrait))
        return CAMERA_ORIENTATION_PORTRAIT;
    return CAMERA_ORIENTATION_LANDSCAPE;
}
void QCameraParameters::setOrientation(int orientation)
{
    if (orientation == CAMERA_ORIENTATION_PORTRAIT) {
        set("orientation", portrait);
    } else {
         set("orientation", landscape);
    }
}

// Parse string like "640x480" or "10000,20000"
static int parse_pair(const char *str, int *first, int *second, char delim,
                      char **endptr = NULL)
{
    // Find the first integer.
    char *end;
    int w = (int)strtol(str, &end, 10);
    // If a delimeter does not immediately follow, give up.
    if (*end != delim) {
        ALOGE("Cannot find delimeter (%c) in str=%s", delim, str);
        return -1;
    }

    // Find the second integer, immediately after the delimeter.
    int h = (int)strtol(end+1, &end, 10);

    *first = w;
    *second = h;

    if (endptr) {
        *endptr = end;
    }

    return 0;
}

// Parse string like "(1, 2, 3, 4, ..., N)"
// num is pointer to an allocated array of size N
static int parseNDimVector(const char *str, int *num, int N, char delim = ',')
{
    char *start, *end;
    if(num == NULL) {
        ALOGE("Invalid output array (num == NULL)");
        return -1;
    }
    //check if string starts and ends with parantheses
    if(str[0] != '(' || str[strlen(str)-1] != ')') {
        ALOGE("Invalid format of string %s, valid format is (n1, n2, n3, n4 ...)", str);
        return -1;
    }
    start = (char*) str;
    start++;
    for(int i=0; i<N; i++) {
        *(num+i) = (int) strtol(start, &end, 10);
        if(*end != delim && i < N-1) {
            ALOGE("Cannot find delimeter '%c' in string \"%s\". end = %c", delim, str, *end);
            return -1;
        }
        start = end+1;
    }
    return 0;
}

static void parseSizesList(const char *sizesStr, Vector<Size> &sizes)
{
    if (sizesStr == 0) {
        return;
    }

    char *sizeStartPtr = (char *)sizesStr;

    while (true) {
        int width, height;
        int success = parse_pair(sizeStartPtr, &width, &height, 'x',
                                 &sizeStartPtr);
        if (success == -1 || (*sizeStartPtr != ',' && *sizeStartPtr != '\0')) {
            ALOGE("Picture sizes string \"%s\" contains invalid character.", sizesStr);
            return;
        }
        sizes.push(Size(width, height));

        if (*sizeStartPtr == '\0') {
            return;
        }
        sizeStartPtr++;
    }
}

void QCameraParameters::getSupportedHfrSizes(Vector<Size> &sizes) const
{
    const char *hfrSizesStr = get(KEY_SUPPORTED_HFR_SIZES);
    parseSizesList(hfrSizesStr, sizes);
}

void QCameraParameters::setPreviewFpsRange(int minFPS, int maxFPS)
{
    char str[32];
    snprintf(str, sizeof(str), "%d,%d",minFPS,maxFPS);
    set(KEY_PREVIEW_FPS_RANGE,str);
}

void QCameraParameters::setPreviewFrameRateMode(const char *mode)
{
    set(KEY_PREVIEW_FRAME_RATE_MODE, mode);
}

const char *QCameraParameters::getPreviewFrameRateMode() const
{
    return get(KEY_PREVIEW_FRAME_RATE_MODE);
}

void QCameraParameters::setTouchIndexAec(int x, int y)
{
    char str[32];
    snprintf(str, sizeof(str), "%dx%d", x, y);
    set(KEY_TOUCH_INDEX_AEC, str);
}

void QCameraParameters::getTouchIndexAec(int *x, int *y) const
{
    *x = -1;
    *y = -1;

    // Get the current string, if it doesn't exist, leave the -1x-1
    const char *p = get(KEY_TOUCH_INDEX_AEC);
    if (p == 0)
        return;

    int tempX, tempY;
    if (parse_pair(p, &tempX, &tempY, 'x') == 0) {
        *x = tempX;
        *y = tempY;
    }
}

void QCameraParameters::setTouchIndexAf(int x, int y)
{
    char str[32];
    snprintf(str, sizeof(str), "%dx%d", x, y);
    set(KEY_TOUCH_INDEX_AF, str);
}

void QCameraParameters::getMeteringAreaCenter(int *x, int *y) const
{
    //Default invalid values
    *x = -2000;
    *y = -2000;

    const char *p = get(KEY_METERING_AREAS);
    if(p != NULL) {
        int arr[5] = {-2000, -2000, -2000, -2000, 0};
        parseNDimVector(p, arr, 5); //p = "(x1, y1, x2, y2, weight)"
        *x = (arr[0] + arr[2])/2; //center_x = (x1+x2)/2
        *y = (arr[1] + arr[3])/2; //center_y = (y1+y2)/2
    }
}

void QCameraParameters::getTouchIndexAf(int *x, int *y) const
{
    *x = -1;
    *y = -1;

    // Get the current string, if it doesn't exist, leave the -1x-1
    const char *p = get(KEY_TOUCH_INDEX_AF);
    if (p == 0)
        return;

    int tempX, tempY;
    if (parse_pair(p, &tempX, &tempY, 'x') == 0) {
        *x = tempX;
        *y = tempY;
    }
}
