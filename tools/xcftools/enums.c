/* Autogenerated from enums.h */
#include "enums.h"
#define N_
#include <stdio.h>
const char*
showGimpLayerModeEffects(GimpLayerModeEffects x)
{
  static char buf[35];
  switch(x) {
    case GIMP_NORMAL_MODE: return N_("Normal");
    case GIMP_DISSOLVE_MODE: return N_("Dissolve");
    case GIMP_BEHIND_MODE: return N_("Behind");
    case GIMP_MULTIPLY_MODE: return N_("Multiply");
    case GIMP_SCREEN_MODE: return N_("Screen");
    case GIMP_OVERLAY_MODE: return N_("Overlay");
    case GIMP_DIFFERENCE_MODE: return N_("Difference");
    case GIMP_ADDITION_MODE: return N_("Addition");
    case GIMP_SUBTRACT_MODE: return N_("Subtract");
    case GIMP_DARKEN_ONLY_MODE: return N_("DarkenOnly");
    case GIMP_LIGHTEN_ONLY_MODE: return N_("LightenOnly");
    case GIMP_HUE_MODE: return N_("Hue");
    case GIMP_SATURATION_MODE: return N_("Saturation");
    case GIMP_COLOR_MODE: return N_("Color");
    case GIMP_VALUE_MODE: return N_("Value");
    case GIMP_DIVIDE_MODE: return N_("Divide");
    case GIMP_DODGE_MODE: return N_("Dodge");
    case GIMP_BURN_MODE: return N_("Burn");
    case GIMP_HARDLIGHT_MODE: return N_("Hardlight");
    case GIMP_SOFTLIGHT_MODE: return N_("Softlight");
    case GIMP_GRAIN_EXTRACT_MODE: return N_("GrainExtract");
    case GIMP_GRAIN_MERGE_MODE: return N_("GrainMerge");
    case GIMP_COLOR_ERASE_MODE: return N_("ColorErase");
    case GIMP_ERASE_MODE: return N_("Erase");
    case GIMP_REPLACE_MODE: return N_("Replace");
    case GIMP_ANTI_ERASE_MODE: return N_("AntiErase");
    case GIMP_NORMAL_NOPARTIAL_MODE: return N_("NormalNopartial");
    default: sprintf(buf,"(GimpLayerModeEffects:%d)",(int)x);
             return buf;
  }
}
const char*
showGimpImageBaseType(GimpImageBaseType x)
{
  static char buf[32];
  switch(x) {
    case GIMP_RGB: return N_("RGB color");
    case GIMP_GRAY: return N_("Grayscale");
    case GIMP_INDEXED: return N_("Indexed color");
    default: sprintf(buf,"(GimpImageBaseType:%d)",(int)x);
             return buf;
  }
}
const char*
showGimpImageType(GimpImageType x)
{
  static char buf[28];
  switch(x) {
    case GIMP_RGB_IMAGE: return N_("RGB");
    case GIMP_RGBA_IMAGE: return N_("RGB-alpha");
    case GIMP_GRAY_IMAGE: return N_("Grayscale");
    case GIMP_GRAYA_IMAGE: return N_("Grayscale-alpha");
    case GIMP_INDEXED_IMAGE: return N_("Indexed");
    case GIMP_INDEXEDA_IMAGE: return N_("Indexed-alpha");
    default: sprintf(buf,"(GimpImageType:%d)",(int)x);
             return buf;
  }
}
const char*
showGimpPrecision(GimpPrecision x)
{
  static char buf[28];
  switch(x) {
    case GIMP_PRECISION_U8_LINEAR: return N_("8-bit linear integer");
    case GIMP_PRECISION_U8_NON_LINEAR: return N_("8-bit non-linear integer");
    case GIMP_PRECISION_U8_PERCEPTUAL: return N_("8-bit perceptual integer");
    case GIMP_PRECISION_U16_LINEAR: return N_("16-bit linear integer");
    case GIMP_PRECISION_U16_NON_LINEAR: return N_("16-bit non-linear integer");
    case GIMP_PRECISION_U16_PERCEPTUAL: return N_("16-bit perceptual integer");
    case GIMP_PRECISION_U32_LINEAR: return N_("32-bit linear integer");
    case GIMP_PRECISION_U32_NON_LINEAR: return N_("32-bit non-linear integer");
    case GIMP_PRECISION_U32_PERCEPTUAL: return N_("32-bit perceptual integer");
    case GIMP_PRECISION_HALF_LINEAR: return N_("16-bit linear floating point");
    case GIMP_PRECISION_HALF_NON_LINEAR: return N_("16-bit non-linear floating point");
    case GIMP_PRECISION_HALF_PERCEPTUAL: return N_("16-bit perceptual floating point");
    case GIMP_PRECISION_FLOAT_LINEAR: return N_("32-bit linear floating point");
    case GIMP_PRECISION_FLOAT_NON_LINEAR: return N_("32-bit non-linear floating point");
    case GIMP_PRECISION_FLOAT_PERCEPTUAL: return N_("32-bit perceptual floating point");
    case GIMP_PRECISION_DOUBLE_LINEAR: return N_("64-bit linear floating point");
    case GIMP_PRECISION_DOUBLE_NON_LINEAR: return N_("64-bit non-linear floating point");
    case GIMP_PRECISION_DOUBLE_PERCEPTUAL: return N_("64-bit perceptual floating point");
    default: sprintf(buf,"(GimpPrecision:%d)",(int)x);
             return buf;
  }
}
const char*
showPropType(PropType x)
{
  static char buf[23];
  switch(x) {
    case PROP_END: return ("End");
    case PROP_COLORMAP: return ("Colormap");
    case PROP_ACTIVE_LAYER: return ("ActiveLayer");
    case PROP_ACTIVE_CHANNEL: return ("ActiveChannel");
    case PROP_SELECTION: return ("Selection");
    case PROP_FLOATING_SELECTION: return ("FloatingSelection");
    case PROP_OPACITY: return ("Opacity");
    case PROP_MODE: return ("Mode");
    case PROP_VISIBLE: return ("Visible");
    case PROP_LINKED: return ("Linked");
    case PROP_LOCK_ALPHA: return ("LockAlpha");
    case PROP_APPLY_MASK: return ("ApplyMask");
    case PROP_EDIT_MASK: return ("EditMask");
    case PROP_SHOW_MASK: return ("ShowMask");
    case PROP_SHOW_MASKED: return ("ShowMasked");
    case PROP_OFFSETS: return ("Offsets");
    case PROP_COLOR: return ("Color");
    case PROP_COMPRESSION: return ("Compression");
    case PROP_GUIDES: return ("Guides");
    case PROP_RESOLUTION: return ("Resolution");
    case PROP_TATTOO: return ("Tattoo");
    case PROP_PARASITES: return ("Parasites");
    case PROP_UNIT: return ("Unit");
    case PROP_PATHS: return ("Paths");
    case PROP_USER_UNIT: return ("UserUnit");
    case PROP_VECTORS: return ("Vectors");
    case PROP_TEXT_LAYER_FLAGS: return ("TextLayerFlags");
    case PROP_SAMPLE_POINTS: return ("SamplePoints");
    case PROP_LOCK_CONTENT: return ("LockContent");
    case PROP_GROUP_ITEM: return ("GroupItem");
    case PROP_ITEM_PATH: return ("ItemPath");
    case PROP_GROUP_ITEM_FLAGS: return ("GroupItemFlags");
    default: sprintf(buf,"(PropType:%d)",(int)x);
             return buf;
  }
}
const char*
showXcfCompressionType(XcfCompressionType x)
{
  static char buf[33];
  switch(x) {
    case COMPRESS_NONE: return N_("None");
    case COMPRESS_RLE: return N_("RLE");
    case COMPRESS_ZLIB: return N_("Zlib");
    case COMPRESS_FRACTAL: return N_("Fractal");
    default: sprintf(buf,"(XcfCompressionType:%d)",(int)x);
             return buf;
  }
}