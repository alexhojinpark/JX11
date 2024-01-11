#pragma once

#include <cmath>

const float PI_OVER_4 = 0.7853981633974483f;
const float PI = 3.1415926535897932f;
const float TWO_PI = 6.2831853071795864f;

class Oscillator
{
private:
    float phase;
    float phaseMax;
    float inc;
    
public:
    float period = 0.0f;
    float amplitude = 1.0f;
    
    float freq;
    float sampleRate;
    float phaseBL; // phase for bandlimited oscillator
    
    void reset()
    {
        inc = 0.0f;
        phase = 0.0f;
    }
    
    float nextSample()
    {
        float output = 0.0f;
        
        phase += inc;
        
        if (phase <= PI_OVER_4)
        {
            float halfPeriod = period / 2.0f;
            phaseMax = std::floor(0.5f + halfPeriod) - 0.5f;
            phaseMax *= PI;
            
            inc = phaseMax / halfPeriod;
            phase = -phase;
            
            if (phase * phase > 1e-9)
            {
                output = amplitude * std::sin(phase) / phase;
            }
            else
            {
                output = amplitude;
            }
        }
        else
        {
            if (phase > phaseMax)
            {
                phase = phaseMax + phaseMax - phase;
                inc = -inc;
            }
            output = amplitude * std::sin(phase) / phase;
        }
        return output;
    }
    
    float nextBandlimitedSample()
    {
        phaseBL += inc;
        if (phaseBL >= 1.0f)
        {
            phaseBL -= 1.0f;
        }
        
        float output = 0.0f;
        float nyquist = sampleRate / 2.0f;
        float h = freq;
        float i = 1.0f;
        float m = 0.6366197724f; // 2/pi
        
        // Adds up sine waves until it reaches the Nyquist limit
        // The sine values are accumulated in the variable output
        while (h < nyquist)
        {
            output += m * std::sin(TWO_PI * phaseBL * i) / i;
            h += freq;
            i += 1.0f;
            m = -m;
        }
        return output;
    }
    
};
