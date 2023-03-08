/*
 * Shortcircuit XT - a Surge Synth Team product
 *
 * A fully featured creative sampler, available as a standalone
 * and plugin for multiple platforms.
 *
 * Copyright 2019 - 2023, Various authors, as described in the github
 * transaction log.
 *
 * ShortcircuitXT is released under the Gnu General Public Licence
 * V3 or later (GPL-3.0-or-later). The license is found in the file
 * "LICENSE" in the root of this repository or at
 * https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Individual sections of code which comprises ShortcircuitXT in this
 * repository may also be used under an MIT license. Please see the
 * section  "Licensing" in "README.md" for details.
 *
 * ShortcircuitXT is inspired by, and shares code with, the
 * commercial product Shortcircuit 1 and 2, released by VemberTech
 * in the mid 2000s. The code for Shortcircuit 2 was opensourced in
 * 2020 at the outset of this project.
 *
 * All source for ShortcircuitXT is available at
 * https://github.com/surge-synthesizer/shortcircuit-xt
 */

#ifndef SHORTCIRCUIT_MODMAPPINGPANE_H
#define SHORTCIRCUIT_MODMAPPINGPANE_H

#include "sst/jucegui/components/NamedPanel.h"
#include "components/HasEditor.h"
#include "modulation/voice_matrix.h"

namespace scxt::ui::multi
{
struct ModRow;

struct ModPane : sst::jucegui::components::NamedPanel, HasEditor
{
    static constexpr int numRowsOnScreen{6};
    ModPane(SCXTEditor *e);
    ~ModPane();

    void resized() override;

    void rebuildMatrix(); // entirely new components
    void refreshMatrix(); // new routing table, no new components
    void setActive(bool b);

    std::array<std::unique_ptr<ModRow>, numRowsOnScreen> rows;

    scxt::modulation::voiceModMatrixMetadata_t matrixMetadata;
    scxt::modulation::VoiceModMatrix::routingTable_t routingTable;

    int tabRange{0};
};
} // namespace scxt::ui::multi
#endif // SHORTCIRCUIT_MAPPINGPANE_H